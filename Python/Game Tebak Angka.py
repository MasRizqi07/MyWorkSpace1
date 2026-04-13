import random
import time

def game_tebak_angka():
    print("\n" + "="*30)
    print("🎯 CHALLENGE: TEBAK ANGKA 🎯")
    print("="*30)
    
    angka_rahasia = random.randint(1, 100)
    nyawa = 7
    
    print(f"Aku memikirkan angka antara 1-100. Kamu punya {nyawa} nyawa!")
    
    while nyawa > 0:
        print(f"\nSisa nyawa: {'❤️ ' * nyawa}")
        try:
            tebakan = int(input("Masukkan tebakanmu: "))
        except ValueError:
            print("❌ Ups! Masukkan angka yang valid ya.")
            continue
            
        if tebakan == angka_rahasia:
            print(f"🎉 LUAR BIASA! Kamu menang! Angkanya memang {angka_rahasia}.")
            break
        elif tebakan < angka_rahasia:
            print("📉 Terlalu RENDAH!")
        else:
            print("📈 Terlalu TINGGI!")
            
        nyawa -= 1
        
    if nyawa == 0:
        print(f"\n💀 Game Over! Angka rahasianya adalah {angka_rahasia}. Coba lagi ya!")

# Jalankan game
game_tebak_angka()