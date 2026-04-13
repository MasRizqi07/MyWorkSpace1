// Kurs tetap (contoh: 1 USD = 15000 IDR, 1 EUR = 16000 IDR)
const rates = {
    USD: { IDR: 15000, EUR: 0.85 },
    EUR: { IDR: 16000, USD: 1.18 },
    IDR: { USD: 1/15000, EUR: 1/16000 }
};

function convertCurrency(amount, from, to) {
    if (!rates[from] || !rates[from][to]) {
        return "Konversi tidak didukung.";
    }
    return amount * rates[from][to];
}

// Fungsi utama
function currencyConverter() {
    console.log("Selamat datang di Konverter Mata Uang!");
    console.log("Mata uang yang didukung: USD, EUR, IDR");

    const amount = parseFloat(prompt("Masukkan jumlah:"));
    const from = prompt("Dari mata uang (USD/EUR/IDR):").toUpperCase();
    const to = prompt("Ke mata uang (USD/EUR/IDR):").toUpperCase();

    if (isNaN(amount)) {
        console.log("Masukkan jumlah yang valid!");
        return;
    }

    const result = convertCurrency(amount, from, to);
    console.log(`${amount} ${from} = ${result} ${to}`);
}

// Jalankan konverter
currencyConverter();