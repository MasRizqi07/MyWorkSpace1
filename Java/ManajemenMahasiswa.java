import java.util.Scanner;

public class ManajemenMahasiswa {

    // ===== ARRAY untuk simpan data =====
    static String[] namaMahasiswa  = new String[10];
    static String[] nimMahasiswa   = new String[10];
    static double[] nilaiMahasiswa = new double[10];
    static int jumlahData = 0;

    static Scanner scanner = new Scanner(System.in);

    // ===================================
    //         MAIN METHOD
    // ===================================
    public static void main(String[] args) {
        int pilihan;

        do {
            tampilkanMenu();
            System.out.print("Pilih menu: ");
            pilihan = scanner.nextInt();
            scanner.nextLine(); // flush buffer

            switch (pilihan) {
                case 1: tambahMahasiswa();   break;
                case 2: tampilkanSemuaData();break;
                case 3: cariMahasiswa();     break;
                case 4: tampilkanStatistik();break;
                case 5: System.out.println("\n👋 Sampai jumpa, bro!"); break;
                default: System.out.println("⚠️  Pilihan tidak valid, coba lagi.");
            }

        } while (pilihan != 5);

        scanner.close();
    }

    // ===================================
    //         METHOD: MENU
    // ===================================
    static void tampilkanMenu() {
        System.out.println("\n╔══════════════════════════════════════╗");
        System.out.println("║     SISTEM MANAJEMEN MAHASISWA       ║");
        System.out.println("╠══════════════════════════════════════╣");
        System.out.println("║  1. Tambah Data Mahasiswa            ║");
        System.out.println("║  2. Tampilkan Semua Data             ║");
        System.out.println("║  3. Cari Mahasiswa (by NIM)          ║");
        System.out.println("║  4. Statistik Nilai                  ║");
        System.out.println("║  5. Keluar                           ║");
        System.out.println("╚══════════════════════════════════════╝");
    }

    // ===================================
    //         METHOD: TAMBAH DATA
    // ===================================
    static void tambahMahasiswa() {
        if (jumlahData >= 10) {
            System.out.println("⚠️  Data sudah penuh! Maksimal 10 mahasiswa.");
            return;
        }

        System.out.println("\n--- Tambah Mahasiswa Baru ---");
        System.out.print("Nama  : ");
        namaMahasiswa[jumlahData] = scanner.nextLine();

        System.out.print("NIM   : ");
        nimMahasiswa[jumlahData] = scanner.nextLine();

        System.out.print("Nilai (0-100): ");
        nilaiMahasiswa[jumlahData] = scanner.nextDouble();
        scanner.nextLine();

        jumlahData++;
        System.out.println("✅ Data berhasil ditambahkan!");
    }

    // ===================================
    //         METHOD: TAMPILKAN DATA
    // ===================================
    static void tampilkanSemuaData() {
        if (jumlahData == 0) {
            System.out.println("\n📭 Belum ada data mahasiswa.");
            return;
        }

        System.out.println("\n--- Daftar Semua Mahasiswa ---");
        System.out.printf("%-5s %-20s %-15s %-8s %-6s%n",
            "No", "Nama", "NIM", "Nilai", "Grade");
        System.out.println("─".repeat(58));

        // LOOPING untuk tampilkan semua data
        for (int i = 0; i < jumlahData; i++) {
            System.out.printf("%-5d %-20s %-15s %-8.1f %-6s%n",
                (i + 1),
                namaMahasiswa[i],
                nimMahasiswa[i],
                nilaiMahasiswa[i],
                tentukanGrade(nilaiMahasiswa[i])
            );
        }

        System.out.println("─".repeat(58));
        System.out.println("Total data: " + jumlahData + " mahasiswa");
    }

    // ===================================
    //         METHOD: CARI MAHASISWA
    // ===================================
    static void cariMahasiswa() {
        if (jumlahData == 0) {
            System.out.println("\n📭 Belum ada data mahasiswa.");
            return;
        }

        System.out.print("\nMasukkan NIM yang dicari: ");
        String nimCari = scanner.nextLine();

        boolean ketemu = false;

        // LOOPING untuk cari data
        for (int i = 0; i < jumlahData; i++) {
            if (nimMahasiswa[i].equals(nimCari)) {
                System.out.println("\n✅ Mahasiswa ditemukan!");
                System.out.println("─".repeat(30));
                System.out.println("Nama  : " + namaMahasiswa[i]);
                System.out.println("NIM   : " + nimMahasiswa[i]);
                System.out.printf("Nilai : %.1f%n", nilaiMahasiswa[i]);
                System.out.println("Grade : " + tentukanGrade(nilaiMahasiswa[i]));
                System.out.println("─".repeat(30));
                ketemu = true;
                break;
            }
        }

        if (!ketemu) {
            System.out.println("❌ NIM " + nimCari + " tidak ditemukan.");
        }
    }

    // ===================================
    //         METHOD: STATISTIK
    // ===================================
    static void tampilkanStatistik() {
        if (jumlahData == 0) {
            System.out.println("\n📭 Belum ada data mahasiswa.");
            return;
        }

        double total   = 0;
        double highest = nilaiMahasiswa[0];
        double lowest  = nilaiMahasiswa[0];
        String namaTertinggi = namaMahasiswa[0];
        String namaTerendah  = namaMahasiswa[0];

        // LOOPING untuk hitung statistik
        for (int i = 0; i < jumlahData; i++) {
            total += nilaiMahasiswa[i];

            if (nilaiMahasiswa[i] > highest) {
                highest = nilaiMahasiswa[i];
                namaTertinggi = namaMahasiswa[i];
            }
            if (nilaiMahasiswa[i] < lowest) {
                lowest = nilaiMahasiswa[i];
                namaTerendah = namaMahasiswa[i];
            }
        }

        double rata = total / jumlahData;

        System.out.println("\n--- 📊 Statistik Nilai ---");
        System.out.println("─".repeat(35));
        System.out.printf("Rata-rata Kelas  : %.2f (%s)%n", rata, tentukanGrade(rata));
        System.out.printf("Nilai Tertinggi  : %.1f → %s%n", highest, namaTertinggi);
        System.out.printf("Nilai Terendah   : %.1f → %s%n", lowest, namaTerendah);
        System.out.println("─".repeat(35));
    }

    // ===================================
    //     METHOD: TENTUKAN GRADE
    // ===================================
    static String tentukanGrade(double nilai) {
        if (nilai >= 85) return "A";
        else if (nilai >= 75) return "B";
        else if (nilai >= 60) return "C";
        else if (nilai >= 50) return "D";
        else return "E";
    }
}
