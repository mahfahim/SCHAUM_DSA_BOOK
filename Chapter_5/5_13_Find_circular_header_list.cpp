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


void FINDITEM(Node* start, int item, Node*& loc, Node*& locp) {
    if (start == NULL) { 
        loc = NULL;
        locp = NULL;
        return;
    }

    Node* save = start;          
    Node* ptr = start->next;     

   
    while (ptr != start && ptr->val != item) {
        save = ptr;             
        ptr = ptr->next;      
    }

   
    if (ptr->val == item) {
        loc = ptr;              
        locp = save;            
    } else {
        loc = NULL;             
        locp = save;          
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
    Node* locp = NULL;
    FINDITEM(header, itemToSearch, loc, locp);

    if (loc) {
        cout << "Item " << itemToSearch << " found at node with address: " << loc 
             << ", preceding node at address: " << locp << endl;
    } else {
        cout << "Item " << itemToSearch << " not found in the list." << endl;
    }

    return 0;
}
