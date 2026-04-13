#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};

class DoubleLinkedList {
private:
    Node* head;
    Node* tail;
    
public:
    DoubleLinkedList() {
        head = NULL;
        tail = NULL;
    }
    
    
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        newNode->prev = NULL;
        
        if (head == NULL) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    
    
    void deleteMultipleOf3() {
        Node* current = head;
        
        while (current != NULL) {
            // Jika kelipatan 3
            if (current->data % 3 == 0) {
                Node* toDelete = current;
                
                
                if (current == head) {
                    head = current->next;
                    if (head != NULL) {
                        head->prev = NULL;
                    } else {
                        tail = NULL;
                    }
                } 
                
                else if (current == tail) {
                    tail = current->prev;
                    tail->next = NULL;
                } 
                
                else {
                    current->prev->next = current->next;
                    current->next->prev = current->prev;
                }
                
                current = current->next;
                delete toDelete;
            } else {
                current = current->next;
            }
        }
    }
    
    
    void displayForward() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }
    
    
    ~DoubleLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    DoubleLinkedList list;
    
    cout << "=== DOUBLE LINKED LIST - HAPUS KELIPATAN 3 ===" << endl;
    cout << "\n1. Membuat linked list dengan angka 1 sampai 100..." << endl;
    
    
    for (int i = 1; i <= 100; i++) {
        list.insertEnd(i);
    }
    
    cout << "\nLinked List sebelum penghapusan (10 elemen pertama):" << endl;
    cout << "1 <-> 2 <-> 3 <-> 4 <-> 5 <-> 6 <-> 7 <-> 8 <-> 9 <-> 10 <-> ... <-> 100" << endl;
    
    cout << "\n2. Menghapus semua kelipatan 3..." << endl;
    list.deleteMultipleOf3();
    
    cout << "\nLinked List setelah penghapusan kelipatan 3:" << endl;
    list.displayForward();
    
    return 0;
}