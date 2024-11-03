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


void PROCESS(int& data) {
   
    cout << data << " ";
}


void traverseCircularList(Node* start) {
    if (start == NULL) return; 

    Node* ptr = start->next; 

    
    while (ptr != start) {
        PROCESS(ptr->val);   
        ptr = ptr->next;     
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

    cout << "Traversing circular list: ";
    traverseCircularList(header);
    cout << endl;

    return 0;
}
