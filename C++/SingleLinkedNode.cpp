#include <iostream>

using namespace std;

struct Node {
    int info;
    Node* next;
};

int main() {
    
    Node* awal = NULL;
    Node* akhir = NULL;
    Node* K = NULL;

    
    for (int i = 1; i <= 17; i++) {
        
        
        if (i % 2 == 0) {
            
            
            K = new Node;
            K->info = i;
            
            
            if (awal == NULL) {
                K->next = NULL;
                awal = K;
                akhir = K;
            }
            
            else if (i / 3.0 <= 2.0) {
                K->next = awal;
                awal = K;
            }
            
            else {
                K->next = NULL;
                akhir->next = K;
                akhir = K;
            }
        }
    }

    
    cout << "Hasil eksekusi Linked List:" << endl;
    
    Node* temp = awal;
    while (temp != NULL) {
        cout << temp->info;
        if (temp->next != NULL) {
            cout << " -> ";
        }
        temp = temp->next;
    }
    cout << " -> NULL" << endl;

    
    temp = awal;
    while (temp != NULL) {
        Node* nextNode = temp->next;
        delete temp;
        temp = nextNode;
    }

    return 0;
}