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
        *head = newNode;
        *tail = newNode;
    } else {
        (*tail)->next = newNode;
        newNode->prev = *tail;
        *tail = newNode;
    }
}

void insertAfter(Node* head, Node** tail, int targetData, int newData) {
    Node* bantu = head;

    
    while (bantu != nullptr && bantu->data != targetData) {
        bantu = bantu->next;
    }

    if (bantu == nullptr) {
        cout << "Data target tidak ditemukan!" << endl;
        return;
    }

    Node* baru = createNode(newData);
    Node* bantu1 = bantu->next;

    
    baru->prev = bantu;
    bantu->next = baru;

    
    if (bantu1 != nullptr) {
        
        baru->next = bantu1;
        bantu1->prev = baru;
    } else {
        
        *tail = baru;
    }
}

void printList(Node* head) {
    Node* temp = head;
    cout << "List Data: ";
    while (temp != nullptr) {
        cout << temp->data << (temp->next ? " <-> " : "");
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int data, choice, target;

    
    do {
        cout << "Masukkan data: ";
        cin >> data;
        insertBack(&head, &tail, data);
        cout << "Tambah data lagi? (1=Ya): ";
        cin >> choice;
    } while (choice == 1);

    printList(head);

    
    cout << "\nApakah ingin sisip tengah? (1=Ya): ";
    cin >> choice;
    if (choice == 1) {
        cout << "Masukkan data baru yang ingin disisip: ";
        cin >> data;
        cout << "Disisipkan SETELAH data apa? ";
        cin >> target;
        insertAfter(head, &tail, target, data);
    }

    printList(head);

    return 0;
}