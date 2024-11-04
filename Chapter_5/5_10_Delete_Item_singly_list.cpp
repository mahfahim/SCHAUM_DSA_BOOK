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


void delete_item(Node*& head, Node*& avail, int item) {
    Node* loc = NULL;
    Node* locp = NULL;

 
    FINDB(head, item, loc, locp);

   
    if (loc == NULL) {
        cout << "ITEM not in list." << endl;
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


void displayList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->val << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    
    Node* avail = NULL;

    
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);

    cout << "Original list: ";
    displayList(head);

    
    int itemTodelete_item = 30;
    delete_item(head, avail, itemTodelete_item);

    cout << "List after deletion: ";
    displayList(head);

    return 0;
}
