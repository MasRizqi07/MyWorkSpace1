// todo-cli.ts
interface Todo {
  id: number;
  task: string;
  completed: boolean;
  createdAt: Date;
}

class TodoApp {
  private todos: Todo[] = [];
  private nextId: number = 1;

  addTask(task: string): void {
    this.todos.push({
      id: this.nextId++,
      task,
      completed: false,
      createdAt: new Date()
    });
    console.log(`✅ Tugas "${task}" berhasil ditambahkan!`);
  }

  listTasks(): void {
    if (this.todos.length === 0) {
      console.log("📭 Belum ada tugas!");
      return;
    }

    console.log("\n📋 DAFTAR TUGAS:");
    console.log("=".repeat(50));

    this.todos.forEach(todo => {
      const status = todo.completed ? "✅" : "⏳";
      const date = todo.createdAt.toLocaleDateString('id-ID');
      console.log(`${status} [${todo.id}] ${todo.task} (${date})`);
    });
    console.log("=".repeat(50));
  }

  completeTask(id: number): void {
    const todo = this.todos.find(t => t.id === id);
    if (todo) {
      todo.completed = true;
      console.log(`🎉 Tugas "${todo.task}" selesai!`);
    } else {
      console.log("❌ Tugas tidak ditemukan!");
    }
  }

  deleteTask(id: number): void {
    const index = this.todos.findIndex(t => t.id === id);
    if (index !== -1) {
      const deletedTask = this.todos.splice(index, 1)[0];
      console.log(`🗑️ Tugas "${deletedTask.task}" dihapus!`);
    } else {
      console.log("❌ Tugas tidak ditemukan!");
    }
  }
}

function showMenu(): void {
  console.log("\n🎯 TODO LIST APP");
  console.log("1. Tambah Tugas");
  console.log("2. Lihat Semua Tugas");
  console.log("3. Selesaikan Tugas");
  console.log("4. Hapus Tugas");
  console.log("0. Keluar");
}

// Main Program
function main(): void {
  const app = new TodoApp();

  const readline = require('readline').createInterface({
    input: process.stdin,
    output: process.stdout
  });

  function askQuestion(question: string): Promise<string> {
    return new Promise((resolve) => {
      readline.question(question, resolve);
    });
  }

  async function run() {
    while (true) {
      showMenu();
      const choice = await askQuestion("Pilih menu (0-4): ");

      switch (choice) {
        case '1':
          const task = await askQuestion("Masukkan tugas: ");
          app.addTask(task);
          break;
        case '2':
          app.listTasks();
          break;
        case '3':
          const completeId = parseInt(await askQuestion("ID tugas yang selesai: "));
          app.completeTask(completeId);
          break;
        case '4':
          const deleteId = parseInt(await askQuestion("ID tugas yang dihapus: "));
          app.deleteTask(deleteId);
          break;
        case '0':
          console.log("👋 Terima kasih!");
          readline.close();
          return;
        default:
          console.log("❌ Pilihan tidak valid!");
      }

      await askQuestion("Tekan Enter untuk melanjutkan...");
    }
  }

  run().catch(console.error);
}

main();