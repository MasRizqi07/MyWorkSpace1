def konverter_mata_uang():
    print("\n" + "$" * 25)
    print("  KONVERTER RUPIAH (IDR)  ")
    print("$" * 25)
    
    try:
        idr = float(input("Masukkan jumlah Rupiah (Rp): "))
    except ValueError:
        print("❌ Masukkan angka saja ya!")
        return

    print("\nPilih target mata uang:")
    print("1. USD (Dollar AS) - Kurs: 15.500")
    print("2. JPY (Yen Jepang) - Kurs: 105")
    print("3. SGD (Dollar Singapura) - Kurs: 11.500")
    
    pilihan = input("Pilih (1-3): ")
    
    if pilihan == '1':
        hasil = idr / 15500
        print(f"\n💵 Hasil: $ {hasil:.2f} USD")
    elif pilihan == '2':
        hasil = idr / 105
        print(f"\n💴 Hasil: ¥ {hasil:.2f} JPY")
    elif pilihan == '3':
        hasil = idr / 11500
        print(f"\n🇸🇬 Hasil: $ {hasil:.2f} SGD")
    else:
        print("❌ Pilihan tidak tersedia.")

# Jalankan konverter
konverter_mata_uang()