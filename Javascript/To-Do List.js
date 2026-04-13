// Array untuk menyimpan tugas
let todos = JSON.parse(localStorage.getItem('todos')) || [];

function tampilkanTodos() {
    console.log("Daftar Tugas:");
    todos.forEach((todo, index) => {
        console.log(`${index + 1}. ${todo.text} - ${todo.selesai ? 'Selesai' : 'Belum Selesai'}`);
    });
}

function tambahTodo(text) {
    todos.push({ text, selesai: false });
    simpanTodos();
    console.log(`Tugas "${text}" ditambahkan.`);
}

function hapusTodo(index) {
    if (index >= 0 && index < todos.length) {
        const removed = todos.splice(index, 1);
        simpanTodos();
        console.log(`Tugas "${removed[0].text}" dihapus.`);
    } else {
        console.log("Index tidak valid!");
    }
}

function tandaiSelesai(index) {
    if (index >= 0 && index < todos.length) {
        todos[index].selesai = !todos[index].selesai;
        simpanTodos();
        console.log(`Tugas "${todos[index].text}" ${todos[index].selesai ? 'ditandai selesai' : 'ditandai belum selesai'}.`);
    } else {
        console.log("Index tidak valid!");
    }
}

function simpanTodos() {
    localStorage.setItem('todos', JSON.stringify(todos));
}

// Fungsi utama untuk interaksi
function todoApp() {
    console.log("Selamat datang di To-Do List!");
    while (true) {
        const perintah = prompt("Pilih: 1. Tampilkan, 2. Tambah, 3. Hapus, 4. Tandai Selesai, 5. Keluar");
        
        switch (perintah) {
            case '1':
                tampilkanTodos();
                break;
            case '2':
                const text = prompt("Masukkan tugas baru:");
                if (text) tambahTodo(text);
                break;
            case '3':
                const hapusIndex = parseInt(prompt("Masukkan nomor tugas untuk dihapus:")) - 1;
                hapusTodo(hapusIndex);
                break;
            case '4':
                const selesaiIndex = parseInt(prompt("Masukkan nomor tugas untuk ditandai selesai:")) - 1;
                tandaiSelesai(selesaiIndex);
                break;
            case '5':
                console.log("Terima kasih!");
                return;
            default:
                console.log("Perintah tidak valid!");
        }
    }
}

// Jalankan app
todoApp();