def daftar_belanja():
    keranjang = []
    
    while True:
        print("\n--- 🛒 MENU KERANJANG BELANJA ---")
        print("1. Lihat Daftar")
        print("2. Tambah Barang")
        print("3. Hapus Barang")
        print("4. Keluar")
        
        pilihan = input("Pilih menu (1-4): ")
        
        if pilihan == '1':
            print("\nIsi Keranjangmu:")
            if not keranjang:
                print("- Masih kosong -")
            for i, item in enumerate(keranjang, 1):
                print(f"{i}. {item}")
        
        elif pilihan == '2':
            item_baru = input("Masukkan nama barang: ")
            keranjang.append(item_baru)
            print(f"✅ {item_baru} berhasil ditambahkan!")
            
        elif pilihan == '3':
            if not keranjang:
                print("❌ Keranjang kosong, tidak ada yang bisa dihapus.")
                continue
            item_hapus = input("Ketik nama barang yang mau dihapus: ")
            if item_hapus in keranjang:
                keranjang.remove(item_hapus)
                print(f"🗑️ {item_hapus} telah dihapus.")
            else:
                print("⚠️ Barang tidak ditemukan.")
                
        elif pilihan == '4':
            print("Sampai jumpa! Jangan lupa belanja ya! 👋")
            break
        else:
            print("❌ Pilihan tidak valid.")

# Jalankan daftar belanja
daftar_belanja()