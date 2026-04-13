// Konfigurasi Tema (Menggunakan CSS Variables agar terpusat)
const themes = {
    red: { color: '#ff4757', filter: 'hue-rotate(0deg)' },
    green: { color: '#2ed573', filter: 'hue-rotate(100deg)' },
    blue: { color: '#1e90ff', filter: 'hue-rotate(220deg)' },
    yellow: { color: '#feca57', filter: 'hue-rotate(45deg)' }
};

// Fungsi Ganti Tema Sepatu Utama
function changeTheme(themeKey, btnElement) {
    const root = document.documentElement;
    const img = document.getElementById('hero-img');
    const buttons = document.querySelectorAll('.color-btn');

    // Update UI tombol
    buttons.forEach(btn => btn.classList.remove('active'));
    btnElement.classList.add('active');

    // Terapkan efek pop
    img.style.transform = window.innerWidth > 992 ? "rotate(-20deg) scale(0.9)" : "rotate(-10deg) scale(0.9)";

    setTimeout(() => {
        // Manipulasi CSS Variable di Root (Sangat efisien!)
        root.style.setProperty('--primary-color', themes[themeKey].color);
        root.style.setProperty('--primary-glow', `${themes[themeKey].color}66`); // 66 = 40% opacity

        // Ubah warna gambar
        img.style.filter = `drop-shadow(-20px 30px 40px rgba(0,0,0,0.8)) ${themes[themeKey].filter}`;

        // Kembalikan ukuran
        img.style.transform = window.innerWidth > 992 ? "rotate(-20deg) scale(1)" : "rotate(-10deg) scale(1)";
    }, 200);
}

// --- SISTEM KERANJANG BELANJA (CART STATE MANAGEMENT) ---
let cart = [];

// Format angka ke Rupiah
const formatRupiah = (number) => {
    return new Intl.NumberFormat('id-ID', { style: 'currency', currency: 'IDR', minimumFractionDigits: 0 }).format(number);
};

// Tambah ke keranjang
function addToCart(productName, price, imgSrcIdOrUrl) {
    // Ambil URL gambar yang benar (dari Hero img id, atau langsung URL text)
    let imageUrl = '';
    if (document.getElementById(imgSrcIdOrUrl)) {
        imageUrl = document.getElementById(imgSrcIdOrUrl).src;
    } else {
        imageUrl = imgSrcIdOrUrl;
    }

    // Tambahkan data ke state array
    cart.push({
        id: Date.now(),
        name: productName,
        price: price,
        image: imageUrl
    });

    updateCartUI();
    showToast();
}

// Hapus dari keranjang
function removeFromCart(id) {
    cart = cart.filter(item => item.id !== id);
    updateCartUI();
}

// Update tampilan keranjang di DOM
function updateCartUI() {
    const cartItemsContainer = document.getElementById('cart-items');
    const cartCount = document.getElementById('cart-count');
    const cartTotal = document.getElementById('cart-total');

    // Update badge jumlah
    cartCount.innerText = cart.length;

    // Render daftar item
    if (cart.length === 0) {
        cartItemsContainer.innerHTML = '<p class="empty-cart">Keranjang masih kosong.</p>';
        cartTotal.innerText = 'Rp 0';
        return;
    }

    let itemsHTML = '';
    let total = 0;

    cart.forEach(item => {
        total += item.price;
        itemsHTML += `
            <div class="cart-item">
                <img src="${item.image}" alt="${item.name}">
                <div class="item-details">
                    <h4>${item.name}</h4>
                    <p>${formatRupiah(item.price)}</p>
                </div>
                <button class="remove-btn" onclick="removeFromCart(${item.id})">
                    <i class="fa-solid fa-trash"></i>
                </button>
            </div>
        `;
    });

    cartItemsContainer.innerHTML = itemsHTML;
    cartTotal.innerText = formatRupiah(total);
}

// Toggle buka/tutup Sidebar Cart
function toggleCart() {
    const sidebar = document.getElementById('cart-sidebar');
    const overlay = document.getElementById('cart-overlay');

    sidebar.classList.toggle('active');
    overlay.classList.toggle('active');
}

// Fungsi Checkout (Simulasi)
function checkout() {
    if (cart.length === 0) {
        alert("Keranjang masih kosong, pilih sepatu dulu bro!");
        return;
    }
    alert(`Pesanan diproses! Total tagihan: ${document.getElementById('cart-total').innerText}\nTerima kasih telah berbelanja.`);
    cart = [];
    updateCartUI();
    toggleCart();
}

// UI Feedback: Toast Notification
function showToast() {
    const toast = document.getElementById('toast');
    toast.classList.add('show');
    setTimeout(() => {
        toast.classList.remove('show');
    }, 3000);
}