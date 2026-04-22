#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

Node* createNode(int value) {
    Node* newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    return newNode;
}

void insertFront(Node** head, Node** tail, int value) {
    Node* newNode = createNode(value);

    if (*head == nullptr) {
        *head = newNode;
        *tail = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}

void displayList(Node* head) {
    Node* temp = head;
    cout << "\nIsi Linked List: ";
    while (temp != nullptr) {
        cout << temp->data << " <-> ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

void clearList(Node** head) {
    Node* current = *head;
    Node* nextNode;
    while (current != nullptr) {
        nextNode = current->next;
        delete current;
        current = nextNode;
    }
    *head = nullptr;
}

int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int dataInput, choice;

    do {
        cout << "Masukkan data: ";
        cin >> dataInput;

        insertFront(&head, &tail, dataInput);

        cout << "Ingin tambah data lagi? (1 = Ya, 0 = Tidak): ";
        cin >> choice;
    } while (choice == 1);

    displayList(head);

    
    clearList(&head);

    return 0;
}