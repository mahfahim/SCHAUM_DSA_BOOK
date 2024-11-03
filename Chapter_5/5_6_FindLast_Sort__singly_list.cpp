#include <iostream>
using namespace std;

class Node
{
    public:
        int val;
        Node* next;
    Node(int val)
    {
        this->val=val;
        this->next=NULL;
    }
};

void FINDA(Node* &head, int item, Node*& loc) {
    
    if (head == NULL) {
        loc = NULL;
        return;
    }


    if (item < head->val) {
        loc = NULL;
        return;
    }

    
    Node* save = head;
    Node* tmp = head->next;

    while (tmp != NULL) {
    
        if (item < tmp->val) {
            loc = save;
            return;
        }
    
        save = tmp;
        tmp = tmp->next;
    }

    
    loc = save;

}

int main() {
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);

    Node* loc = NULL;
    int item = 25;

    FINDA(head, item, loc);

    if (loc) {
        cout << "Location found. Info at LOC: " << loc->next << endl;
    } else {
        cout << "Location not found." << endl;
    }


    return 0;
}
