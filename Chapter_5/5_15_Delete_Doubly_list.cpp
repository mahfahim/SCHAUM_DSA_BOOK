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


void DELTWL(Node*& start, Node*& avail, int loc, Node* forw[], Node* back[]) {
    if (loc < 0 || loc >= 100) { 
        cout << "Invalid location." << endl;
        return;
    }

    
    Node* nodeToDelete = forw[loc]; 
    if (nodeToDelete == NULL) {
        cout << "Node does not exist at the specified location." << endl;
        return;
    }

   
    if (nodeToDelete->prev != NULL) {
        nodeToDelete->prev->next = nodeToDelete->next; 
    } else {
        start = nodeToDelete->next; 
    }
    
    if (nodeToDelete->next != NULL) {
        nodeToDelete->next->prev = nodeToDelete->prev;
    }

    
    forw[loc] = avail; /////////////
    avail = nodeToDelete; //////////

    cout << "Node with value " << nodeToDelete->val << " deleted from the list." << endl;
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
    Node* second = new Node(20);
    Node* third = new Node(30);
    
    start->next = second;
    second->prev = start;
    second->next = third;
    third->prev = second;

    
    Node* forw[100] = {nullptr}; 
    Node* back[100] = {nullptr}; 

    
    forw[0] = start; 
    forw[1] = second; 
    forw[2] = third; 
    back[1] = start; 
    back[2] = second; 

    
    cout << "Current list: ";
    printList(start);

    
    DELTWL(start, forw[0], 1, forw, back);

    
    cout << "List after deletion: ";
    printList(start);

    return 0;
}
