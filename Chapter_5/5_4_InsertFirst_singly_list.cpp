
#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;

    Node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

void INSFIRST(Node*& start, Node*& avail, int item) {

    if (avail == NULL) {
        cout << "OVERFLOW" << endl;
        return;
    }

    
    Node* newNode = avail;  
    avail = avail->next;     


    newNode->val = item;


    newNode->next = start;   
    start = newNode;         

    cout << "Inserted " << item << " as the first node." << endl;
}


void printList(Node* start) {
    Node* current = start;
    while (current != NULL) {
        cout << current->val << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    
    Node* avail = new Node(0);
    avail->next = new Node(0);
    avail->next->next = new Node(0); 

    Node* start = NULL; 

    
    cout << "Initial list: ";
    printList(start);

    
    INSFIRST(start, avail, 10);
    INSFIRST(start, avail, 20);
    INSFIRST(start, avail, 30);

    
    cout << "List after insertion: ";
    printList(start);

    

    return 0;
}
