import json
import os

DATA_FILE = "data.json"

def load_data():
    if os.path.exists(DATA_FILE):
        with open(DATA_FILE, "r") as file:
            return json.load(file)
    return []

def save_data(data):
    with open(DATA_FILE, "w") as file:
        json.dump(data, file, indent=4)

def tambah_data(data):
    print("\n=== TAMBAH DATA MAHASISWA ===")
    nama = input("Nama Mahasiswa : ")
    nim = input("NIM : ")
    prodi = input("Program Studi : ")

    for mhs in data:
        if mhs["nim"] == nim:
            print("⚠️ NIM sudah terdaftar, input gagal.")
            return

    data.append({"nama": nama, "nim": nim, "prodi": prodi})
    save_data(data)
    print("✔ Data berhasil ditambahkan!")

def tampilkan_data(data):
    print("\n=== DAFTAR MAHASISWA ===")
    if len(data) == 0:
        print("Belum ada data mahasiswa.")
    else:
        for mhs in data:
            print(f"Nama: {mhs['nama']} | NIM: {mhs['nim']} | Prodi: {mhs['prodi']}")

def cari_data(data):
    print("\n=== CARI DATA ===")
    nim = input("Masukkan NIM yang dicari : ")
    for mhs in data:
        if mhs["nim"] == nim:
            print(f"Ditemukan! Nama: {mhs['nama']}, Prodi: {mhs['prodi']}")
            return
    print("❌ Data tidak ditemukan.")

def hapus_data(data):
    print("\n=== HAPUS DATA ===")
    nim = input("Masukkan NIM yang ingin dihapus : ")
    for mhs in data:
        if mhs["nim"] == nim:
            data.remove(mhs)
            save_data(data)
            print("🗑 Data berhasil dihapus.")
            return
    print("❌ Data tidak ditemukan.")

def main():
    data = load_data()

    while True:
        print("\n====== MENU APLIKASI DATA MAHASISWA ======")
        print("1. Tambah Data")
        print("2. Tampilkan Data")
        print("3. Cari Data")
        print("4. Hapus Data")
        print("5. Keluar")
        pilihan = input("Pilih menu (1-5): ")

        match pilihan:
            case "1": tambah_data(data)
            case "2": tampilkan_data(data)
            case "3": cari_data(data)
            case "4": hapus_data(data)
            case "5":
                print("Selesai. Bye 👋")
                break
            case _:
                print("Input tidak valid, coba lagi.")

if __name__ == "__main__":
    main()
