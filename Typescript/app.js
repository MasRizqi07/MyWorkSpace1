// 2. Class untuk mengelola daftar tugas
var TaskManager = /** @class */ (function () {
    function TaskManager() {
        this.tasks = [];
    }
    // Menambah tugas baru
    TaskManager.prototype.addTask = function (title) {
        var newTask = {
            id: this.tasks.length + 1,
            title: title,
            isCompleted: false
        };
        this.tasks.push(newTask);
        console.log("\u2705 Berhasil menambah: \"".concat(title, "\""));
    };
    // Menampilkan semua tugas
    TaskManager.prototype.showTasks = function () {
        console.log("\n--- DAFTAR TUGAS ---");
        if (this.tasks.length === 0) {
            console.log("Belum ada tugas.");
        }
        else {
            this.tasks.forEach(function (task) {
                var status = task.isCompleted ? "[✔]" : "[ ]";
                console.log("".concat(task.id, ". ").concat(status, " ").concat(task.title));
            });
        }
        console.log("--------------------\n");
    };
    return TaskManager;
}());
// 3. Eksekusi Program
var myApp = new TaskManager();
myApp.addTask("Belajar TypeScript Dasar");
myApp.addTask("Setup Projek di VS Code");
myApp.addTask("Ngopi sambil Debugging");
myApp.showTasks();
