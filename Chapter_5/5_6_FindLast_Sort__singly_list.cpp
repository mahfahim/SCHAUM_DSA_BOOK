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

void FINDA(Node* &start, int item, Node*& loc) {
    
    if (start == NULL) {
        loc = NULL;
        return;
    }


    if (item < start->val) {
        loc = NULL;
        return;
    }

    
    Node* save = start;
    Node* tmp = start->next;

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
    Node* start = new Node(10);
    start->next = new Node(20);
    start->next->next = new Node(30);

    Node* loc = NULL;
    int item = 25;

    FINDA(start, item, loc);

    if (loc) {
        cout << "Location found. Info at LOC: " << loc->next << endl;
    } else {
        cout << "Location not found." << endl;
    }


    return 0;
}
