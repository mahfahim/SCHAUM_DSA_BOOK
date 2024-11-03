#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* prev;

    Node(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

void INSTWL(Node*& start, Node*& avail, Node* loca, Node* locb, int item) {
    
    if (avail == NULL) {
        cout << "OVERFLOW" << endl;
        return;
    }

    
    Node* newNode = avail;          
    avail = avail->next;           

    newNode->val = item;            
    newNode->next = NULL;         
    newNode->prev = NULL;

    
    newNode->next = locb;            
    newNode->prev = loca;             

    if (loca != NULL) {
        loca->next = newNode;        
    } else {
        start = newNode;              
    }

    if (locb != NULL) {
        locb->prev = newNode;         
    }

    cout << "Inserted " << item << " between nodes ";
    if (loca) cout << loca->val << " and ";
    if (locb) cout << locb->val;
    cout << endl;
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
    
    Node* start = new Node(10);
    start->next = new Node(20);
    start->next->prev = start;
    start->next->next = new Node(30);
    start->next->next->prev = start->next;

    Node* avail = new Node(0);  

    cout << "Original list: ";
    printList(start);

    
    INSTWL(start, avail, start, start->next, 15);

    cout << "List after insertion: ";
    printList(start);

    return 0;
}
