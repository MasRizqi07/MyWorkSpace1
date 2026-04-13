import java.util.Scanner;

public class GradeCalculator {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);

        System.out.println("========================================");
        System.out.println("   STUDENT GRADE CALCULATOR - ITATS    ");
        System.out.println("========================================");

        System.out.print("Masukkan nama kamu: ");
        String nama = scanner.nextLine();

        System.out.print("Masukkan nilai Tugas  (0-100): ");
        double tugas = scanner.nextDouble();

        System.out.print("Masukkan nilai UTS    (0-100): ");
        double uts = scanner.nextDouble();

        System.out.print("Masukkan nilai UAS    (0-100): ");
        double uas = scanner.nextDouble();

        // Hitung nilai akhir dengan bobot
        double nilaiAkhir = (tugas * 0.30) + (uts * 0.30) + (uas * 0.40);

        // Tentukan grade
        String grade;
        String status;

        if (nilaiAkhir >= 85) {
            grade = "A";
            status = "Lulus dengan Pujian 🏆";
        } else if (nilaiAkhir >= 75) {
            grade = "B";
            status = "Lulus ✅";
        } else if (nilaiAkhir >= 60) {
            grade = "C";
            status = "Lulus ✅";
        } else if (nilaiAkhir >= 50) {
            grade = "D";
            status = "Tidak Lulus ❌";
        } else {
            grade = "E";
            status = "Tidak Lulus ❌";
        }

        // Output hasil
        System.out.println("\n========================================");
        System.out.println("   HASIL NILAI AKHIR                    ");
        System.out.println("========================================");
        System.out.println("Nama       : " + nama);
        System.out.printf("Tugas (30%%): %.1f%n", tugas);
        System.out.printf("UTS   (30%%): %.1f%n", uts);
        System.out.printf("UAS   (40%%): %.1f%n", uas);
        System.out.println("----------------------------------------");
        System.out.printf("Nilai Akhir: %.2f%n", nilaiAkhir);
        System.out.println("Grade      : " + grade);
        System.out.println("Status     : " + status);
        System.out.println("========================================");

        scanner.close();
    }
}