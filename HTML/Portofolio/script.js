/**
 * 1. Easter Egg for Recruiters & Fellow Devs
 * Nunjukkin lu paham tools developer.
 */
console.log(
    "%c🚀 Pacoel.Dev System Initialized.",
    "color: #38bdf8; font-size: 16px; font-weight: bold; background: #0f172a; padding: 10px; border-radius: 5px;"
);
console.log("Looking for spaghetti code? You won't find it here. Clean architecture only.");

/**
 * 2. Mobile Menu Toggle
 */
const mobileBtn = document.getElementById('mobile-menu-btn');
const navLinks = document.getElementById('nav-links');

mobileBtn.addEventListener('click', () => {
    navLinks.classList.toggle('active');
    // Ganti icon List ke X pas menu kebuka
    const icon = mobileBtn.querySelector('i');
    if (navLinks.classList.contains('active')) {
        icon.className = 'ph ph-x';
    } else {
        icon.className = 'ph ph-list';
    }
});

/**
 * 3. Dynamic Case Studies (Modal Logic)
 * Menyimpan data proyek di JS biar HTML tetap bersih.
 */
const projectData = {
    'ecommerce': {
        title: 'High-End E-Commerce',
        tech: 'JavaScript ES6, CSS Grid, LocalStorage',
        problem: 'Sistem keranjang belanja statis sering kali membebani server dan membuat pengalaman UX menjadi lambat bagi pengguna.',
        solution: 'Membangun state management keranjang belanja dinamis di sisi klien (client-side) yang merender data secara instan tanpa perlu memuat ulang halaman.'
    },
    'finance': {
        title: 'Wealth Tracker Dashboard',
        tech: 'Vanilla JS, Chart.js (Simulated), CSS Variables',
        problem: 'Sulitnya melacak akumulasi aset kompleks dan memproyeksikan target finansial jangka panjang secara visual.',
        solution: 'Mengembangkan dashboard interaktif dengan algoritma kalkulasi real-time untuk memvisualisasikan matriks aset dan pengeluaran.'
    }
};

const modal = document.getElementById('project-modal');
const closeModalBtn = document.querySelector('.close-modal');
const modalTitle = document.getElementById('modal-title');
const modalTech = document.getElementById('modal-tech');
const modalProblem = document.getElementById('modal-problem');
const modalSolution = document.getElementById('modal-solution');

// Buka Modal
document.querySelectorAll('.open-modal').forEach(btn => {
    btn.addEventListener('click', function () {
        // Ambil ID proyek dari attribute data-project di elemen parent-nya (.project-card)
        const projectId = this.closest('.project-card').getAttribute('data-project');
        const data = projectData[projectId];

        if (data) {
            modalTitle.textContent = data.title;
            modalTech.textContent = data.tech;
            modalProblem.textContent = data.problem;
            modalSolution.textContent = data.solution;
            modal.classList.add('active');
        }
    });
});

// Tutup Modal
closeModalBtn.addEventListener('click', () => modal.classList.remove('active'));
modal.addEventListener('click', (e) => {
    if (e.target === modal) modal.classList.remove('active'); // Tutup kalau klik area luar modal
});

/**
 * 4. Intersection Observer & Smooth Scroll (Sama kayak sebelumnya, tapi lebih optimized)
 */
const scrollObserver = new IntersectionObserver((entries, observer) => {
    entries.forEach(entry => {
        if (entry.isIntersecting) {
            entry.target.classList.add('is-visible');
            observer.unobserve(entry.target);
        }
    });
}, { threshold: 0.15 });

document.querySelectorAll('.fade-in').forEach(el => {
    el.classList.add('is-hidden');
    scrollObserver.observe(el);
});

// Smooth Scroll
document.querySelectorAll('a[href^="#"]').forEach(anchor => {
    anchor.addEventListener('click', function (e) {
        e.preventDefault();
        const targetId = this.getAttribute('href');
        if (targetId === '#') return;

        // Tutup mobile menu otomatis pas link di-klik
        navLinks.classList.remove('active');
        mobileBtn.querySelector('i').className = 'ph ph-list';

        const targetElement = document.querySelector(targetId);
        if (targetElement) {
            targetElement.scrollIntoView({ behavior: 'smooth', block: 'start' });
        }
    });
});

/**
 * 5. Theme Switcher Persistence
 */
const toggleBtn = document.getElementById('theme-toggle');
const rootElement = document.documentElement;
const savedTheme = localStorage.getItem('pacoel-theme') || 'dark';

rootElement.setAttribute('data-theme', savedTheme);
updateToggleUI(savedTheme);

toggleBtn.addEventListener('click', () => {
    const currentTheme = rootElement.getAttribute('data-theme');
    const newTheme = currentTheme === 'dark' ? 'light' : 'dark';

    rootElement.setAttribute('data-theme', newTheme);
    localStorage.setItem('pacoel-theme', newTheme);
    updateToggleUI(newTheme);
});

function updateToggleUI(theme) {
    const icon = toggleBtn.querySelector('i');
    if (theme === 'dark') {
        icon.className = 'ph ph-sun';
    } else {
        icon.className = 'ph ph-moon';
    }
}