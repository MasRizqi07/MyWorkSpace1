package main

import (
	"fmt"
	"math/rand"
	"os"
	"time"
)

func clearScreen() {
	fmt.Println("\n\n")
}


func generateRandom(min, max int) int {
	return rand.Intn(max-min+1) + min
}


func printBanner() {
	fmt.Println("╔══════════════════════════════════════╗")
	fmt.Println("║       🎮 TEBAK ANGKA - GOLANG        ║")
	fmt.Println("║     Dibuat pakai Go | Beginner lvl   ║")
	fmt.Println("╚══════════════════════════════════════╝")
}


func printResult(attempts int, maxAttempts int) {
	fmt.Println("\n╔══════════════════════════════════════╗")
	if attempts == 1 {
		fmt.Println("║  🏆 LUAR BIASA! Tebakan pertama!     ║")
	} else if attempts <= maxAttempts/2 {
		fmt.Printf("║  🔥 KEREN! Cuma %d kali tebakan!       ║\n", attempts)
	} else {
		fmt.Printf("║  ✅ BERHASIL dalam %d tebakan!         ║\n", attempts)
	}
	fmt.Println("╚══════════════════════════════════════╝")
}


func pilihDifficulty() (int, int, string) {
	fmt.Println("\n📋 Pilih Level Kesulitan:")
	fmt.Println("  [1] 🟢 Mudah   — Angka 1-50   | 10 kesempatan")
	fmt.Println("  [2] 🟡 Sedang  — Angka 1-100  | 7 kesempatan")
	fmt.Println("  [3] 🔴 Susah   — Angka 1-200  | 5 kesempatan")
	fmt.Print("\nMasukkan pilihan (1/2/3): ")

	var choice int
	fmt.Scan(&choice)

	switch choice {
	case 1:
		return 50, 10, "🟢 Mudah"
	case 2:
		return 100, 7, "🟡 Sedang"
	case 3:
		return 200, 5, "🔴 Susah"
	default:
		fmt.Println("⚠️  Pilihan ga valid, default ke Mudah.")
		return 50, 10, "🟢 Mudah"
	}
}


func playGame() bool {
	clearScreen()
	printBanner()

	
	maxNumber, maxAttempts, levelName := pilihDifficulty()

	
	rand.Seed(time.Now().UnixNano())
	secretNumber := generateRandom(1, maxNumber)

	fmt.Printf("\n🎯 Level: %s\n", levelName)
	fmt.Printf("🔢 Tebak angka antara 1 sampai %d\n", maxNumber)
	fmt.Printf("💡 Kamu punya %d kesempatan\n", maxAttempts)
	fmt.Println("━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━")

	attempts := 0
	menang := false

	
	for attempts < maxAttempts {
		attempts++
		sisaKesempatan := maxAttempts - attempts + 1

		fmt.Printf("\n[Tebakan ke-%d | Sisa: %d kesempatan]\n", attempts, sisaKesempatan)
		fmt.Print("👉 Masukkan tebakan kamu: ")

		var tebakan int
		_, err := fmt.Scan(&tebakan)

		
		if err != nil {
			fmt.Println("❌ Input ga valid! Masukkan angka saja.")
			attempts-- 
			continue
		}

		
		if tebakan < 1 || tebakan > maxNumber {
			fmt.Printf("⚠️  Angka harus antara 1 dan %d!\n", maxNumber)
			attempts--
			continue
		}

		
		if tebakan < secretNumber {
			gap := secretNumber - tebakan
			if gap > 20 {
				fmt.Println("📉 Terlalu KECIL! Masih jauh nih...")
			} else if gap > 5 {
				fmt.Println("📈 Terlalu KECIL! Tapi udah deket~")
			} else {
				fmt.Println("🔥 Terlalu KECIL! Hampir banget!")
			}
		} else if tebakan > secretNumber {
			gap := tebakan - secretNumber
			if gap > 20 {
				fmt.Println("📉 Terlalu BESAR! Masih jauh nih...")
			} else if gap > 5 {
				fmt.Println("📉 Terlalu BESAR! Tapi udah deket~")
			} else {
				fmt.Println("🔥 Terlalu BESAR! Hampir banget!")
			}
		} else {
			
			fmt.Printf("\n🎉 YEAYYY! Angkanya adalah %d!\n", secretNumber)
			printResult(attempts, maxAttempts)
			menang = true
			break
		}
	}

	
	if !menang {
		fmt.Println("\n╔══════════════════════════════════════╗")
		fmt.Println("║  😢 GAME OVER! Kesempatan habis!     ║")
		fmt.Printf("║  Angka yang benar adalah: %-11d║\n", secretNumber)
		fmt.Println("╚══════════════════════════════════════╝")
	}

	
	fmt.Print("\n🔄 Main lagi? (y/n): ")
	var jawab string
	fmt.Scan(&jawab)

	return jawab == "y" || jawab == "Y"
}

func main() {
	fmt.Println("Selamat datang di Tebak Angka! 🚀")
	fmt.Println("Game ini dibuat pakai Golang untuk belajar dasar-dasar Go.")

	
	for {
		mainLagi := playGame()
		if !mainLagi {
			fmt.Println("\n👋 Makasih udah main! Sampai jumpa!")
			fmt.Println("   ~ dibuat dengan 💙 pakai Go ~\n")
			os.Exit(0)
		}
	}
}