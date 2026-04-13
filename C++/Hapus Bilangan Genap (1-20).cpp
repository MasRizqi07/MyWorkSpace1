#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

class SingleLinkedList {
private:
    Node* head;
    
public:
    SingleLinkedList() {
        head = NULL;
    }
    
    
    void insertEnd(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = NULL;
        
        if (head == NULL) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }
    
    
    void deleteEven() {
        Node* current = head;
        Node* prev = NULL;
        
        while (current != NULL) {
            
            if (current->data % 2 == 0) {
                
                if (prev == NULL) {
                    head = current->next;
                    delete current;
                    current = head;
                } 
                
                else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }
    }
    
    
    void display() {
        Node* temp = head;
        while (temp != NULL) {
            cout << temp->data;
            if (temp->next != NULL) {
                cout << " -> ";
            }
            temp = temp->next;
        }
        cout << " -> NULL" << endl;
    }
    
    
    ~SingleLinkedList() {
        Node* current = head;
        while (current != NULL) {
            Node* next = current->next;
            delete current;
            current = next;
        }
    }
};

int main() {
    SingleLinkedList list;
    
    cout << "=== SINGLE LINKED LIST - HAPUS BILANGAN GENAP ===" << endl;
    cout << "\n1. Membuat linked list dengan angka 1 sampai 20..." << endl;
    
    
    for (int i = 1; i <= 20; i++) {
        list.insertEnd(i);
    }
    
    cout << "\nLinked List sebelum penghapusan:" << endl;
    list.display();
    
    cout << "\n2. Menghapus semua bilangan genap..." << endl;
    list.deleteEven();
    
    cout << "\nLinked List setelah penghapusan bilangan genap:" << endl;
    list.display();
    
    return 0;
}