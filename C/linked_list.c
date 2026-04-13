#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definisi struktur node untuk Linked List
struct Node {
    int data;              // Data yang disimpan
    struct Node *next;     // Pointer ke node berikutnya
};

// Pointer global untuk menandai head (awal) list
struct Node *head = NULL;

// Fungsi untuk membuat node baru
struct Node* createNode(int data) {
    // Alokasi memori dinamis untuk satu node
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    
    // Cek apakah alokasi berhasil
    if (newNode == NULL) {
        printf("Gagal mengalokasikan memori!\n");
        return NULL;
    }
    
    // Inisialisasi data dan pointer
    newNode->data = data;
    newNode->next = NULL;
    
    return newNode;
}

// Fungsi untuk menambah node di awal list (Insert at Beginning)
void insertAtBeginning(int data) {
    struct Node *newNode = createNode(data);
    
    if (newNode == NULL) return;
    
    // Jika list kosong, node baru menjadi head
    if (head == NULL) {
        head = newNode;
    } else {
        // Node baru menunjuk ke head lama, lalu head diperbarui
        newNode->next = head;
        head = newNode;
    }
    
    printf("Data %d berhasil ditambahkan di awal.\n", data);
}

// Fungsi untuk menambah node di akhir list (Insert at End)
void insertAtEnd(int data) {
    struct Node *newNode = createNode(data);
    
    if (newNode == NULL) return;
    
    // Jika list kosong, node baru menjadi head
    if (head == NULL) {
        head = newNode;
    } else {
        // Cari node terakhir
        struct Node *current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        
        // Node terakhir menunjuk ke node baru
        current->next = newNode;
    }
    
    printf("Data %d berhasil ditambahkan di akhir.\n", data);
}

// Fungsi untuk menambah node di posisi tertentu
void insertAtPosition(int data, int position) {
    struct Node *newNode = createNode(data);
    
    if (newNode == NULL) return;
    
    // Jika posisi 1, tambahkan di awal
    if (position == 1) {
        newNode->next = head;
        head = newNode;
        printf("Data %d berhasil ditambahkan di posisi %d.\n", data, position);
        return;
    }
    
    // Cari node sebelum posisi yang dituju
    struct Node *current = head;
    int count = 1;
    
    while (current != NULL && count < position - 1) {
        current = current->next;
        count++;
    }
    
    // Jika posisi melebihi panjang list
    if (current == NULL) {
        printf("Posisi tidak valid!\n");
        free(newNode);  // Bebaskan memori node yang tidak terpakai
        return;
    }
    
    // Sisipkan node baru
    newNode->next = current->next;
    current->next = newNode;
    
    printf("Data %d berhasil ditambahkan di posisi %d.\n", data, position);
}

// Fungsi untuk menghapus node berdasarkan data
void deleteByData(int data) {
    struct Node *current = head;
    struct Node *prev = NULL;
    
    // Jika head adalah node yang dihapus
    if (current != NULL && current->data == data) {
        head = current->next;
        free(current);
        printf("Data %d berhasil dihapus.\n", data);
        return;
    }
    
    // Cari node yang akan dihapus
    while (current != NULL && current->data != data) {
        prev = current;
        current = current->next;
    }
    
    // Jika data tidak ditemukan
    if (current == NULL) {
        printf("Data %d tidak ditemukan!\n", data);
        return;
    }
    
    // Hapus node
    prev->next = current->next;
    free(current);
    printf("Data %d berhasil dihapus.\n", data);
}

// Fungsi untuk menghapus node berdasarkan posisi
void deleteByPosition(int position) {
    struct Node *current = head;
    struct Node *prev = NULL;
    int count = 1;
    
    // Jika posisi 1
    if (position == 1 && head != NULL) {
        head = head->next;
        free(current);
        printf("Node di posisi %d berhasil dihapus.\n", position);
        return;
    }
    
    // Cari node pada posisi yang dituju
    while (current != NULL && count < position) {
        prev = current;
        current = current->next;
        count++;
    }
    
    // Jika posisi tidak valid
    if (current == NULL) {
        printf("Posisi tidak valid!\n");
        return;
    }
    
    // Hapus node
    prev->next = current->next;
    free(current);
    printf("Node di posisi %d berhasil dihapus.\n", position);
}

// Fungsi untuk menghitung jumlah node
int countNodes() {
    struct Node *current = head;
    int count = 0;
    
    while (current != NULL) {
        count++;
        current = current->next;
    }
    
    return count;
}

// Fungsi untuk menampilkan semua data dalam list
void displayList() {
    struct Node *current = head;
    
    if (head == NULL) {
        printf("List kosong!\n");
        return;
    }
    
    printf("\n=== DAFTAR DATA ===\n");
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
    printf("Total node: %d\n", countNodes());
}

// Fungsi untuk mencari data dalam list
int searchNode(int data) {
    struct Node *current = head;
    int position = 1;
    
    while (current != NULL) {
        if (current->data == data) {
            return position;
        }
        current = current->next;
        position++;
    }
    
    return -1;  // Data tidak ditemukan
}

// Fungsi untuk membebaskan semua memori (Clean Up)
void freeList() {
    struct Node *current = head;
    struct Node *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    head = NULL;
    printf("Semua memori berhasil dibebaskan!\n");
}

// Fungsi untuk menampilkan menu
void tampilkanMenu() {
    printf("\n=== MANAJEMEN LINKED LIST ===\n");
    printf("1. Tambah di Awal\n");
    printf("2. Tambah di Akhir\n");
    printf("3. Tambah di Posisi\n");
    printf("4. Hapus Berdasarkan Data\n");
    printf("5. Hapus Berdasarkan Posisi\n");
    printf("6. Tampilkan Semua Data\n");
    printf("7. Cari Data\n");
    printf("8. Hitung Jumlah Node\n");
    printf("9. Keluar dan Bersihkan Memori\n");
    printf("Pilih menu (1-9): ");
}

int main() {
    int pilihan, data, position;
    
    printf("=== IMPLEMENTASI LINKED LIST ===\n");
    printf("Program ini menggunakan dynamic memory allocation.\n");
    printf("Pastikan semua memori dibebaskan saat keluar.\n\n");
    
    while (1) {
        tampilkanMenu();
        scanf("%d", &pilihan);
        
        switch (pilihan) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &data);
                insertAtBeginning(data);
                break;
            case 2:
                printf("Masukkan data: ");
                scanf("%d", &data);
                insertAtEnd(data);
                break;
            case 3:
                printf("Masukkan data: ");
                scanf("%d", &data);
                printf("Masukkan posisi: ");
                scanf("%d", &position);
                insertAtPosition(data, position);
                break;
            case 4:
                printf("Masukkan data yang akan dihapus: ");
                scanf("%d", &data);
                deleteByData(data);
                break;
            case 5:
                printf("Masukkan posisi yang akan dihapus: ");
                scanf("%d", &position);
                deleteByPosition(position);
                break;
            case 6:
                displayList();
                break;
            case 7:
                printf("Masukkan data yang dicari: ");
                scanf("%d", &data);
                int pos = searchNode(data);
                if (pos != -1) {
                    printf("Data %d ditemukan di posisi %d.\n", data, pos);
                } else {
                    printf("Data %d tidak ditemukan.\n", data);
                }
                break;
            case 8:
                printf("Jumlah node: %d\n", countNodes());
                break;
            case 9:
                freeList();
                printf("Program selesai. Terima kasih!\n");
                return 0;
            default:
                printf("Pilihan tidak valid! Silakan coba lagi.\n");
        }
    }
    
    return 0;
}