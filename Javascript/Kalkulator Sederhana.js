function kalkulator() {
    console.log("Selamat datang di Kalkulator Sederhana!");
    console.log("Operasi yang didukung: +, -, *, /");

    // Baris 6 dan 8:
    const num1 = Number.parseFloat(prompt("Masukkan angka pertama:"));
    const num2 = Number.parseFloat(prompt("Masukkan angka kedua:"));

    // Baris 10:
    if (Number.isNaN(num1) || Number.isNaN(num2)) {
        console.log("Masukkan angka yang valid!");
        // ...
    }

    while (true) {
        const operator = prompt("Masukkan operator (+, -, *, /):");
        if (!['+', '-', '*', '/'].includes(operator)) {
            console.log("Operator tidak valid! Silakan coba lagi.");
            continue;
        }

        let hasil;
        switch (operator) {
            case '+':
                hasil = num1 + num2;
                break;
            case '-':
                hasil = num1 - num2;
                break;
            case '*':
                hasil = num1 * num2;
                break;
            case '/':
                if (num2 === 0) {
                    console.log("Tidak bisa membagi dengan nol!");
                    continue;
                }
                hasil = num1 / num2;
                break;
            default:
                console.log("Operator tidak valid!");
                continue;
        }

        console.log(`Hasil: ${num1} ${operator} ${num2} = ${hasil}`);

        const lagi = prompt("Apakah ingin menghitung lagi? (y/n):");
        if (lagi.toLowerCase() !== 'y') break;
    }
}

// Jalankan kalkulator
kalkulator();