#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertBack(Node** head, Node** tail, int value) {
    Node* newNode = createNode(value);
    if (*tail == nullptr) {
        *head = *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void deleteFront(Node** head, Node** tail) {
    if (*head == nullptr) {
        cout << "Maaf, list sudah kosong!" << endl;
        return;
    }

    Node* temp = *head;

    if (*head == *tail) {
        *head = *tail = nullptr;
    } else {
        *head = (*head)->next;
        (*head)->prev = nullptr;
    }

    delete temp;
    cout << "Data awal berhasil dihapus." << endl;
}

void displayList(Node* head) {
    if (head == nullptr) {
        cout << "List Kosong.";
    } else {
        Node* curr = head;
        while (curr != nullptr) {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int val, choice;

    
    do {
        cout << "Masukkan data: ";
        cin >> val;
        insertBack(&head, &tail, val);
        cout << "Ingin tambah akhir lagi? (1=Ya): ";
        cin >> choice;
    } while (choice == 1);

    cout << "\nKondisi awal: ";
    displayList(head);

    
    cout << "\nApakah ingin hapus data awal? (1=Ya): ";
    cin >> choice;

    if (choice == 1) {
        int hapusLagi;
        do {
            deleteFront(&head, &tail);
            cout << "List saat ini: ";
            displayList(head);
            
            if (head == nullptr) break;

            cout << "Ingin hapus lagi? (1=Ya): ";
            cin >> hapusLagi;
        } while (hapusLagi == 1);
    }

    return 0;
}