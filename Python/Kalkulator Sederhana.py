# Kalkulator Sederhana
# Program ini menjalankan operasi matematika dasar: +, -, *, /

def kalkulator():
    print("Selamat datang di Kalkulator Sederhana!")
    print("Operasi yang tersedia: +, -, *, /")
    
    while True:
        try:
            # Input angka pertama
            num1 = float(input("Masukkan angka pertama: "))
            
            # Input operator
            operator = input("Masukkan operator (+, -, *, /): ")
            
            # Input angka kedua
            num2 = float(input("Masukkan angka kedua: "))
            
            # Hitung berdasarkan operator
            if operator == '+':
                hasil = num1 + num2
            elif operator == '-':
                hasil = num1 - num2
            elif operator == '*':
                hasil = num1 * num2
            elif operator == '/':
                if num2 == 0:
                    print("Error: Pembagian dengan nol tidak diperbolehkan!")
                    continue
                hasil = num1 / num2
            else:
                print("Operator tidak valid! Gunakan +, -, *, atau /.")
                continue
            
            # Tampilkan hasil
            print(f"Hasil: {num1} {operator} {num2} = {hasil}")
            
            # Tanya apakah ingin lanjut
            lagi = input("Apakah ingin menghitung lagi? (y/n): ").lower()
            if lagi != 'y':
                print("Terima kasih telah menggunakan kalkulator!")
                break
        
        except ValueError:
            print("Input tidak valid! Masukkan angka yang benar.")

# Jalankan program
if __name__ == "__main__":
    kalkulator()