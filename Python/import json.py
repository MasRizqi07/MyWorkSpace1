import json
import os
from datetime import datetime

try:
    from colorama import Fore, Style, init
    init(autoreset=True)
except ImportError:
    class _NoColor:
        def __getattr__(self, name):
            return ""
    Fore = _NoColor()
    Style = _NoColor()

    def init(autoreset=False):
        pass

DATA_FILE = "tasks.json"

# ---------- FUNGSI UTILITAS ----------
def load_tasks():
    if not os.path.exists(DATA_FILE):
        return []
    with open(DATA_FILE, "r") as file:
        return json.load(file)

def save_tasks(tasks):
    with open(DATA_FILE, "w") as file:
        json.dump(tasks, file, indent=4)

def validate_date(date_str):
    try:
        return datetime.strptime(date_str, "%Y-%m-%d")
    except ValueError:
        return None

# ---------- FITUR UTAMA ----------
def add_task():
    os.system("cls" if os.name == "nt" else "clear")
    print(Fore.CYAN + "=== Tambah Tugas Baru ===")
    title = input("Judul tugas: ").strip()
    desc = input("Deskripsi: ").strip()
    deadline = input("Deadline (YYYY-MM-DD): ").strip()
    date_obj = validate_date(deadline)
    if not date_obj:
        print(Fore.RED + "❌ Format tanggal salah! Gunakan YYYY-MM-DD.")
        return
    priority = input("Prioritas (1=Rendah, 2=Sedang, 3=Tinggi): ").strip()
    if priority not in ["1", "2", "3"]:
        print(Fore.RED + "❌ Prioritas tidak valid.")
        return

    tasks = load_tasks()
    task = {
        "title": title,
        "desc": desc,
        "deadline": deadline,
        "priority": int(priority),
        "created": datetime.now().strftime("%Y-%m-%d %H:%M:%S")
    }
    tasks.append(task)
    save_tasks(tasks)
    print(Fore.GREEN + "✅ Tugas berhasil ditambahkan!")

def show_tasks():
    os.system("cls" if os.name == "nt" else "clear")
    tasks = load_tasks()
    if not tasks:
        print(Fore.YELLOW + "Belum ada tugas yang tersimpan.")
        return

    # Urutkan: prioritas tinggi dulu, lalu deadline paling dekat
    tasks.sort(key=lambda x: (-x["priority"], x["deadline"]))

    print(Fore.CYAN + "=== Daftar Tugas ===")
    for i, task in enumerate(tasks, start=1):
        color = Fore.RED if task["priority"] == 3 else (Fore.YELLOW if task["priority"] == 2 else Fore.GREEN)
        print(f"\n{color}{i}. {task['title']}")
        print(Style.DIM + f"   Deskripsi : {task['desc']}")
        print(Style.DIM + f"   Deadline  : {task['deadline']}")
        print(Style.DIM + f"   Prioritas : {task['priority']}")
        print(Style.DIM + f"   Dibuat    : {task['created']}")

def delete_task():
    os.system("cls" if os.name == "nt" else "clear")
    tasks = load_tasks()
    if not tasks:
        print(Fore.YELLOW + "Tidak ada tugas untuk dihapus.")
        return

    show_tasks()
    try:
        index = int(input("\nMasukkan nomor tugas yang ingin dihapus: "))
        if 1 <= index <= len(tasks):
            deleted = tasks.pop(index - 1)
            save_tasks(tasks)
            print(Fore.GREEN + f"✅ Tugas '{deleted['title']}' berhasil dihapus!")
        else:
            print(Fore.RED + "❌ Nomor tugas tidak valid.")
    except ValueError:
        print(Fore.RED + "❌ Input harus berupa angka.")

def main_menu():
    while True:
        print(Fore.MAGENTA + "\n=== SISTEM MANAJEMEN TUGAS ===")
        print("1. Tambah Tugas")
        print("2. Lihat Semua Tugas")
        print("3. Hapus Tugas")
        print("4. Keluar")

        choice = input("Pilih menu (1-4): ").strip()

        if choice == "1":
            add_task()
        elif choice == "2":
            show_tasks()
        elif choice == "3":
            delete_task()
        elif choice == "4":
            print(Fore.CYAN + "Sampai jumpa! Data tersimpan otomatis.")
            break
        else:
            print(Fore.RED + "❌ Pilihan tidak valid.")

# ---------- ENTRY POINT ----------
if __name__ == "__main__":
    main_menu()
