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


void SEARCH(Node* start, int item, Node*& loc) {
    if (start == NULL) { 
        loc = NULL;
        return;
    }

    Node* ptr = start->next; 

   
    while (ptr != start && ptr->val != item) {
        ptr = ptr->next; 
    }

    
    if (ptr->val == item) {
        loc = ptr;
    } else {
        loc = NULL; 
    }
}

int main() {
   
    Node* header = new Node(-1); 
    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);

    
    header->next = first;
    first->next = second;
    second->next = third;
    third->next = header; 
    
    int itemToSearch = 20;
    Node* loc = NULL;
    SEARCH(header, itemToSearch, loc);

    if (loc) {
        cout << "Item " << itemToSearch << " found at node with address: " << loc << endl;
    } else {
        cout << "Item " << itemToSearch << " not found in the list." << endl;
    }

    return 0;
}
