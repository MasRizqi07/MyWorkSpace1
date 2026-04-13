#include <iostream>
#include <unordered_map>
#include <string>
#include <shared_mutex>
#include <thread>
#include <chrono>
#include <optional>
#include <atomic>
#include <vector>
#include <mutex>

// Namespace khusus biar rapi dan nggak bentrok sama library lain
namespace mrip_redis {

    // Struktur untuk menyimpan data beserta waktu kadaluarsanya (TTL)
    template <typename T>
    struct CacheItem {
        T value;
        std::chrono::time_point<std::chrono::steady_clock> expires_at;
        bool has_ttl;
    };

    // Class Utama Database
    template <typename K, typename V>
    class InMemoryDB {
    private:
        std::unordered_map<K, CacheItem<V>> store;
        mutable std::shared_mutex rw_mutex; // C++17: Mutual exclusion untuk Read/Write
        
        // Komponen Garbage Collector (GC)
        std::atomic<bool> gc_running;
        std::thread gc_thread;
        int gc_interval_ms;

        // Fungsi internal yang jalan di background buat ngebersihin data basi
        void garbage_collector() {
            while (gc_running.load()) {
                std::this_thread::sleep_for(std::chrono::milliseconds(gc_interval_ms));
                
                // Pake exclusive lock karena kita mau menghapus (write) data
                std::unique_lock lock(rw_mutex);
                auto now = std::chrono::steady_clock::now();
                
                for (auto it = store.begin(); it != store.end(); ) {
                    if (it->second.has_ttl && it->second.expires_at < now) {
                        // Hapus kalau udah expired
                        it = store.erase(it);
                    } else {
                        ++it;
                    }
                }
            }
        }

    public:
        // Constructor: Inisialisasi interval GC dan nyalain background thread
        InMemoryDB(int cleanup_interval = 1000) : gc_interval_ms(cleanup_interval), gc_running(true) {
            gc_thread = std::thread(&InMemoryDB::garbage_collector, this);
        }

        // Destructor: Mastiin thread mati dengan aman pas program tutup (No Memory Leak!)
        ~InMemoryDB() {
            gc_running.store(false);
            if (gc_thread.joinable()) {
                gc_thread.join();
            }
        }

        // [SET] Menyimpan data dengan opsi TTL (dalam milidetik)
        void set(const K& key, const V& value, int ttl_ms = 0) {
            std::unique_lock lock(rw_mutex); // Kunci eksklusif untuk nulis data
            
            CacheItem<V> item;
            item.value = value;
            if (ttl_ms > 0) {
                item.has_ttl = true;
                item.expires_at = std::chrono::steady_clock::now() + std::chrono::milliseconds(ttl_ms);
            } else {
                item.has_ttl = false;
            }
            
            store[key] = item;
        }

        // [GET] Mengambil data. Pake std::optional karena data bisa aja gak ada (atau udah expired)
        std::optional<V> get(const K& key) const {
            std::shared_lock lock(rw_mutex); // Kunci sharing untuk baca data (Multiple readers allowed)
            
            auto it = store.find(key);
            if (it != store.end()) {
                // Cek apakah data udah basi pas mau diambil (Lazy expiration)
                if (it->second.has_ttl && it->second.expires_at < std::chrono::steady_clock::now()) {
                    return std::nullopt; // Udah basi, balikin kosong
                }
                return it->second.value;
            }
            return std::nullopt;
        }

        // [DEL] Menghapus data manual
        bool del(const K& key) {
            std::unique_lock lock(rw_mutex);
            return store.erase(key) > 0;
        }
    };
} // end namespace

// --- BAGIAN TESTING & SIMULASI ---
// Mutex buat print ke console biar outputnya nggak berantakan pas multithreading
std::mutex cout_mutex;

void simulate_client(int client_id, mrip_redis::InMemoryDB<std::string, std::string>& db) {
    std::string key = "User_" + std::to_string(client_id);
    std::string value = "Data_Penting_" + std::to_string(client_id);
    
    // Client nge-set data dengan TTL 2 detik (2000 ms)
    db.set(key, value, 2000);
    
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        std::cout << "[Client " << client_id << "] SET " << key << " -> " << value << " (TTL 2s)\n";
    }

    // Client langsung coba nge-GET datanya
    auto result = db.get(key);
    {
        std::lock_guard<std::mutex> lock(cout_mutex);
        if (result) {
            std::cout << "[Client " << client_id << "] GET " << key << " -> " << result.value() << "\n";
        }
    }
}

int main() {
    std::cout << "=== Starting MripRedis Engine ===\n\n";

    // Inisialisasi DB dengan key String dan value String
    mrip_redis::InMemoryDB<std::string, std::string> my_db(500); // GC jalan tiap 500ms

    // Simulasi 5 Client nyerang database barengan (Multithreading)
    std::vector<std::thread> clients;
    for (int i = 1; i <= 5; ++i) {
        clients.push_back(std::thread(simulate_client, i, std::ref(my_db)));
    }

    // Tungguin semua client selesai
    for (auto& t : clients) {
        t.join();
    }

    std::cout << "\n[System] Semua client selesai. Nunggu 3 detik biar TTL expired...\n";
    std::this_thread::sleep_for(std::chrono::seconds(3));

    // Cek lagi apakah data udah dihapus sama Garbage Collector
    std::cout << "\n[System] Cek data User_1 setelah 3 detik:\n";
    auto result_after_ttl = my_db.get("User_1");
    if (result_after_ttl) {
        std::cout << "Data masih ada: " << result_after_ttl.value() << "\n";
    } else {
        std::cout << "Data udah lenyap (Garbage Collector bekerja / Expired!).\n";
    }

    std::cout << "\n=== Engine Shutting Down ===\n";
    return 0;
}