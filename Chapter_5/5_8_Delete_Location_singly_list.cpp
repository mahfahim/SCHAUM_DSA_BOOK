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


void delete_at_loc (Node*& head, Node*& avail, Node* loc, Node* locp) {
    if (loc == NULL) { 
        cout << "Error: Node to delete does not exist." << endl;
        return;
    }

  
    if (locp == NULL) { 
        head = head->next;
    } else { 
        locp->next = loc->next;
    }

   
    loc->next = avail;
    avail = loc;
}


Node* findNode(Node* head, int item, Node*& locp) {
    Node* current = head;
    locp = NULL;

    while (current != NULL) {
        if (current->val == item) {
            return current; 
        }
        locp = current;
        current = current->next;
    }

    return NULL; 
}


void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    Node* avail = new Node(0); 
    Node* temp = avail;
    for (int i = 1; i < 10; i++) { 
        temp->next = new Node(0);
        temp = temp->next;
    }

    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    cout << "Original list: ";
    displayList(head);

    
    int itemToDelete = 20;
    Node* locp = NULL;
    Node* loc = findNode(head, itemToDelete, locp);

    delete_at_loc(head, avail, loc, locp);

    cout << "List after deletion: ";
    displayList(head);

    return 0;
}
