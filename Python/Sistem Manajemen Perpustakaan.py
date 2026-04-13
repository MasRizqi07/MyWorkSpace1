import json
import os
from datetime import datetime, timedelta

# --- KONFIGURASI ---
DENDA_PER_HARI = 2000
BATAS_HARI_PINJAM = 7

class SistemPerpustakaanKompleks:
    def __init__(self):
        self.file_buku = "data_buku.json"
        self.file_anggota = "data_anggota.json"
        self.daftar_buku = self.muat_data(self.file_buku)
        self.daftar_anggota = self.muat_data(self.file_anggota)

    def muat_data(self, nama_file):
        if os.path.exists(nama_file):
            with open(nama_file, 'r') as f:
                return json.load(f)
        return {}

    def simpan_semua_data(self):
        with open(self.file_buku, 'w') as f:
            json.dump(self.daftar_buku, f, indent=4)
        with open(self.file_anggota, 'w') as f:
            json.dump(self.daftar_anggota, f, indent=4)

    def tambah_buku(self):
        isbn = input("Masukkan ISBN: ")
        judul = input("Judul Buku: ")
        stok = int(input("Jumlah Stok: "))
        self.daftar_buku[isbn] = {"judul": judul, "stok": stok}
        self.simpan_semua_data()
        print(f"✅ Buku '{judul}' ditambahkan.")

    def registrasi_anggota(self):
        id_m = input("Masukkan ID Anggota: ")
        nama = input("Nama Lengkap: ")
        self.daftar_anggota[id_m] = {"nama": nama, "pinjaman": {}}
        self.simpan_semua_data()
        print(f"✅ Anggota {nama} berhasil didaftarkan.")

    def pinjam_buku(self):
        id_m = input("ID Anggota: ")
        if id_m not in self.daftar_anggota:
            print("❌ Anggota tidak ditemukan!"); return

        isbn = input("ISBN Buku: ")
        if isbn in self.daftar_buku and self.daftar_buku[isbn]['stok'] > 0:
            # Catat tanggal sekarang
            tgl_pinjam = datetime.now().strftime("%Y-%m-%d %H:%M:%S")
            self.daftar_anggota[id_m]['pinjaman'][isbn] = tgl_pinjam
            self.daftar_buku[isbn]['stok'] -= 1
            
            self.simpan_semua_data()
            print(f"✅ Berhasil dipinjam pada: {tgl_pinjam}")
        else:
            print("❌ Buku tidak tersedia.")

    def kembalikan_buku(self):
        id_m = input("ID Anggota: ")
        if id_m not in self.daftar_anggota:
            print("❌ ID Anggota tidak ditemukan!"); return

        isbn = input("ISBN Buku yang dikembalikan: ")
        pinjaman = self.daftar_anggota[id_m]['pinjaman']

        if isbn in pinjaman:
            # --- LOGIKA HITUNG DENDA ---
            tgl_pinjam = datetime.strptime(pinjaman[isbn], "%Y-%m-%d %H:%M:%S")
            tgl_kembali = datetime.now()
            selisih = tgl_kembali - tgl_pinjam
            
            hari_terlambat = selisih.days - BATAS_HARI_PINJAM
            
            print(f"\nDurasi pinjam: {selisih.days} hari")
            if hari_terlambat > 0:
                total_denda = hari_terlambat * DENDA_PER_HARI
                print(f"⚠️ TERLAMBAT {hari_terlambat} hari!")
                print(f"💰 DENDA YANG HARUS DIBAYAR: Rp {total_denda:,}")
            else:
                print("✅ Pengembalian tepat waktu. Tidak ada denda.")

            # Update Data
            del self.daftar_anggota[id_m]['pinjaman'][isbn]
            self.daftar_buku[isbn]['stok'] += 1
            self.simpan_semua_data()
            print("✅ Data perpustakaan telah diperbarui.")
        else:
            print("❌ Buku ini tidak tercatat dipinjam oleh anggota tersebut.")

    def menu(self):
        while True:
            print("\n--- 🏛️ DIGITAL LIBRARY + AUTO FINES ---")
            print("1. Daftar Buku | 2. Tambah Buku | 3. Registrasi Anggota")
            print("4. Pinjam Buku | 5. Kembalikan Buku | 6. Keluar")
            p = input("Pilih: ")
            if p == '1': 
                for k, v in self.daftar_buku.items(): print(f"[{k}] {v['judul']} - Stok: {v['stok']}")
            elif p == '2': self.tambah_buku()
            elif p == '3': self.registrasi_anggota()
            elif p == '4': self.pinjam_buku()
            elif p == '5': self.kembalikan_buku()
            elif p == '6': break

if __name__ == "__main__":
    app = SistemPerpustakaanKompleks()
    app.menu()