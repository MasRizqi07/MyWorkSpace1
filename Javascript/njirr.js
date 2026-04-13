/**
 * Advanced Particle Physics Engine
 * Fitur: Gravitasi, Friksi, Interaksi Mouse, dan Tabrakan Dinding
 */

class Particle {
    constructor(x, y, radius, color, velocity) {
        this.x = x;
        this.y = y;
        this.radius = radius;
        this.color = color;
        this.velocity = velocity;
        this.mass = 1;
        this.friction = 0.99; // Perlambatan bertahap
        this.gravity = 0.25;  // Kekuatan tarikan ke bawah
    }

    draw(context) {
        context.beginPath();
        context.arc(this.x, this.y, this.radius, 0, Math.PI * 2, false);
        context.fillStyle = this.color;
        context.fill();
        context.closePath();
    }

    update(canvas) {
        // Pantulan Dinding Bawah
        if (this.y + this.radius + this.velocity.y > canvas.height) {
            this.velocity.y = -this.velocity.y * this.friction;
        } else {
            this.velocity.y += this.gravity;
        }

        // Pantulan Dinding Samping
        if (this.x + this.radius + this.velocity.x > canvas.width || this.x - this.radius <= 0) {
            this.velocity.x = -this.velocity.x * this.friction;
        }

        // Update Posisi
        this.x += this.velocity.x;
        this.y += this.velocity.y;
    }
}

class Simulation {
    constructor(canvasId) {
        this.canvas = document.getElementById(canvasId);
        this.ctx = this.canvas.getContext('2d');
        this.particles = [];
        this.mouse = { x: undefined, y: undefined };
        
        this.initCanvas();
        this.animate();
        this.addEventListeners();
    }

    initCanvas() {
        this.canvas.width = window.innerWidth;
        this.canvas.height = window.innerHeight;
    }

    addEventListeners() {
        window.addEventListener('mousedown', (e) => {
            this.spawnParticles(e.clientX, e.clientY);
        });

        window.addEventListener('resize', () => this.initCanvas());
    }

    spawnParticles(x, y) {
        const particleCount = 15;
        for (let i = 0; i < particleCount; i++) {
            const radius = Math.random() * 10 + 5;
            const color = `hsl(${Math.random() * 360}, 70%, 50%)`;
            const velocity = {
                x: (Math.random() - 0.5) * 10,
                y: (Math.random() - 0.5) * 10
            };
            this.particles.push(new Particle(x, y, radius, color, velocity));
        }
    }

    animate() {
        requestAnimationFrame(() => this.animate());
        
        // Efek Trail (jejak) dengan opacity rendah
        this.ctx.fillStyle = 'rgba(0, 0, 0, 0.05)';
        this.ctx.fillRect(0, 0, this.canvas.width, this.canvas.height);

        this.particles.forEach((particle, index) => {
            // Hapus partikel jika sudah terlalu pelan/kecil (optimasi memori)
            if (Math.abs(particle.velocity.y) < 0.1 && particle.y > this.canvas.height - particle.radius - 1) {
                setTimeout(() => {
                    this.particles.splice(index, 1);
                }, 0);
            }
            particle.update(this.canvas);
            particle.draw(this.ctx);
        });
    }
}

// Inisialisasi Program
// Pastikan ada <canvas id="simCanvas"></canvas> di HTML Anda
// const sim = new Simulation('simCanvas');