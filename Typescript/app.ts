// 1. Mendefinisikan struktur data menggunakan Interface
interface Task {
    id: number;
    title: string;
    isCompleted: boolean;
}

// 2. Class untuk mengelola daftar tugas
class TaskManager {
    private tasks: Task[] = [];

    // Menambah tugas baru
    addTask(title: string): void {
        const newTask: Task = {
            id: this.tasks.length + 1,
            title: title,
            isCompleted: false
        };
        this.tasks.push(newTask);
        console.log(`✅ Berhasil menambah: "${title}"`);
    }

    // Menampilkan semua tugas
    showTasks(): void {
        console.log("\n--- DAFTAR TUGAS ---");
        if (this.tasks.length === 0) {
            console.log("Belum ada tugas.");
        } else {
            this.tasks.forEach(task => {
                const status = task.isCompleted ? "[✔]" : "[ ]";
                console.log(`${task.id}. ${status} ${task.title}`);
            });
        }
        console.log("--------------------\n");
    }
}

// 3. Eksekusi Program
const myApp = new TaskManager();

myApp.addTask("Belajar TypeScript Dasar");
myApp.addTask("Setup Projek di VS Code");
myApp.addTask("Ngopi sambil Debugging");

myApp.showTasks();