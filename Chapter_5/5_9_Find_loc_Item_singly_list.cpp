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


void FINDB(Node* head, int item, Node*& loc, Node*& locp) {
    if (head == NULL) { 
        loc = NULL;
        locp = NULL;
        return;
    }

    if (head->val == item) { 
        loc = head;
        locp = NULL;
        return;
    }

    Node* save = head;
    Node* ptr = head->next;

    while (ptr != NULL) {
        if (ptr->val == item) { 
            loc = ptr;
            locp = save;
            return;
        }
        save = ptr;
        ptr = ptr->next;
    }

  
    loc = NULL;
    locp = NULL;
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
    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list: ";
    displayList(head);

    
    int itemToFind = 30;
    Node* loc = NULL;
    Node* locp = NULL;
    FINDB(head, itemToFind, loc, locp);

    if (loc != NULL) {
        cout << "Node with value " << itemToFind << " found." << endl;
        if (locp != NULL) {
            cout << "Preceding node value: " << locp->val << endl;
        } else {
            cout << "The node is the first node in the list." << endl;
        }
    } else {
        cout << "Node with value " << itemToFind << " not found." << endl;
    }

    return 0;
}
