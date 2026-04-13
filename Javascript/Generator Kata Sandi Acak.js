function generatePassword(length = 12, includeUpper = true, includeNumbers = true, includeSymbols = true) {
    const lower = 'abcdefghijklmnopqrstuvwxyz';
    const upper = 'ABCDEFGHIJKLMNOPQRSTUVWXYZ';
    const numbers = '0123456789';
    const symbols = '!@#$%^&*()_+[]{}|;:,.<>?';

    let chars = lower;
    if (includeUpper) chars += upper;
    if (includeNumbers) chars += numbers;
    if (includeSymbols) chars += symbols;

    let password = '';
    for (let i = 0; i < length; i++) {
        password += chars.charAt(Math.floor(Math.random() * chars.length));
    }

    return password;
}

// Fungsi utama
function passwordGenerator() {
    console.log("Selamat datang di Generator Kata Sandi!");
    const length = parseInt(prompt("Masukkan panjang kata sandi (default 12):")) || 12;
    const includeUpper = confirm("Sertakan huruf besar? (OK untuk ya)");
    const includeNumbers = confirm("Sertakan angka? (OK untuk ya)");
    const includeSymbols = confirm("Sertakan simbol? (OK untuk ya)");

    const password = generatePassword(length, includeUpper, includeNumbers, includeSymbols);
    console.log(`Kata sandi yang dihasilkan: ${password}`);
}

// Jalankan generator
passwordGenerator();