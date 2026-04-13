import time
import colorama
from colorama import Fore, Style

colorama.init(autoreset=True)

def animate_heart():
    heart = [
        "   ♥   ",
        "  ♥ ♥  ",
        " ♥   ♥ ",
        "♥     ♥",
        " ♥   ♥ ",
        "  ♥ ♥  ",
        "   ♥   "
    ]
    for line in heart:
        print(Fore.RED + line)
        time.sleep(0.1)

def main():
    print(Fore.MAGENTA + "Selamat datang di Generator Pesan Cinta! 💖")
    nama_anda = input("Masukkan nama Anda: ")
    nama_pasangan = input("Masukkan nama pasangan Anda: ")
    perasaan = input("Jelaskan perasaan Anda singkat (misal: 'sangat mencintai'): ")
    
    print("\n" + Fore.CYAN + "Membuat pesan cinta khusus untuk Anda...")
    time.sleep(1)
    
    pesan = f"""
{Fore.YELLOW}Hai {nama_pasangan},

Aku {nama_anda} ingin mengatakan bahwa aku {perasaan} kamu. 
Kamu adalah cahaya dalam hidupku, dan aku tidak bisa bayangkan hari tanpa kamu. 
Aku cinta kamu selamanya! 💕

Dengan cinta,
{nama_anda}
"""
    
    print(pesan)
    print(Fore.GREEN + "Animasi hati untukmu:")
    animate_heart()
    
    lagi = input("Ingin buat pesan lagi? (y/n): ").lower()
    if lagi == 'y':
        main()
    else:
        print(Fore.BLUE + "Terima kasih! Sampai jumpa lagi. 😊")

if __name__ == "__main__":
    main()