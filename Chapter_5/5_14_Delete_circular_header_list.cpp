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


void DELETEITEM(Node*& start, Node*& avail, int item) {
    Node* loc = NULL;  
    Node* locp = NULL; 

    
    FINDITEM(start, item, loc, locp);

    if (loc == NULL) { 
        cout << "ITEM not in list." << endl;
        return;
    }

    
    if (locp == start) {
        start->next = loc->next; 
    } else {
        locp->next = loc->next; 
    }

    
    loc->next = avail;
    avail = loc;

    cout << "ITEM " << item << " deleted from the list." << endl;
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

    Node* avail = NULL; 

    
    int itemToDelete = 20;
    DELETEITEM(header, avail, itemToDelete);

    
    Node* ptr = header->next; 
    cout << "Remaining items in the list: ";
    if (ptr != header) { 
        do {
            cout << ptr->val << " ";
            ptr = ptr->next; 
        } while (ptr != header);
    } else {
        cout << "List is empty.";
    }
    cout << endl;

    return 0;
}
