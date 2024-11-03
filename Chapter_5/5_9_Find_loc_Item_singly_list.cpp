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


void FINDB(Node* start, int item, Node*& loc, Node*& locp) {
    if (start == NULL) { 
        loc = NULL;
        locp = NULL;
        return;
    }

    if (start->val == item) { 
        loc = start;
        locp = NULL;
        return;
    }

    Node* save = start;
    Node* ptr = start->next;

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


void displayList(Node* start) {
    Node* temp = start;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    Node* start = new Node(10);
    start->next = new Node(20);
    start->next->next = new Node(30);
    start->next->next->next = new Node(40);

    cout << "Original list: ";
    displayList(start);

    
    int itemToFind = 30;
    Node* loc = NULL;
    Node* locp = NULL;// loc er ager node
    FINDB(start, itemToFind, loc, locp);

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
