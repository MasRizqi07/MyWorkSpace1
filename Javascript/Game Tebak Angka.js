// Fungsi utama untuk game tebak angka
function tebakAngka() {
    // Generate angka acak antara 1-100
    const angkaRahasia = Math.floor(Math.random() * 100) + 1;
    let tebakan = null;
    let jumlahTebakan = 0;
    const maksTebakan = 10; // Batas maksimal tebakan

    console.log("Selamat datang di Game Tebak Angka!");
    console.log("Saya telah memilih angka antara 1-100. Coba tebak!");
    console.log(`Anda memiliki ${maksTebakan} kesempatan.`);

    while (tebakan !== angkaRahasia && jumlahTebakan < maksTebakan) {
        // Minta input dari pengguna (di browser, gunakan prompt)
        tebakan = parseInt(prompt("Masukkan tebakan Anda (1-100):"));
        
        if (isNaN(tebakan)) {
            console.log("Masukkan angka yang valid!");
            continue;
        }

        jumlahTebakan++;

        if (tebakan < angkaRahasia) {
            console.log("Terlalu rendah! Coba lagi.");
        } else if (tebakan > angkaRahasia) {
            console.log("Terlalu tinggi! Coba lagi.");
        } else {
            console.log(`Selamat! Anda menebak dengan benar dalam ${jumlahTebakan} tebakan.`);
            return; // Keluar dari fungsi jika benar
        }
    }

    // Jika gagal setelah maksimal tebakan
    if (jumlahTebakan >= maksTebakan) {
        console.log(`Maaf, Anda kehabisan kesempatan. Angka rahasianya adalah ${angkaRahasia}.`);
    }
}

// Jalankan game
tebakAngka();