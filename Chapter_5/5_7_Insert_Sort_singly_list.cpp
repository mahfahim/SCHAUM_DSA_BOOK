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


void FINDA(Node* start, int item, Node*& loc) {
    if (start == NULL || item < start->val) { 
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


void INSLOC(Node*& start, Node*& avail, Node* loc, int item) {
    if (avail == NULL) { 
        cout << "Overflow" << endl;
        return;
    }

    Node* newNode = avail; 
    avail = avail->next;   

    newNode->val = item;
    newNode->next = NULL;

    if (loc == NULL) { 
        newNode->next = start;
        start = newNode;
    } else { 
        newNode->next = loc->next;
        loc->next = newNode;
    }
}


void INSSRT(Node*& start, Node*& avail, int item) 
{
    Node* loc = NULL;
    FINDA(start, item, loc); 
    INSLOC(start, avail, loc, item); 

}
void displayList(Node* &start)
{
    Node* temp = start;
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

    Node* start = NULL; 

  
    INSSRT(start, avail, 10);
    INSSRT(start, avail, 20);
    INSSRT(start, avail, 15);
    INSSRT(start, avail, 5);

   
    displayList(start);

    return 0;
}
