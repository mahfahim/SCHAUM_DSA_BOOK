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

void INSLOC(Node*& start, Node*& avail, Node* loc, int item) 
{
    
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


void displayList(Node* start) {
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
    Node* loc = NULL; 


    INSLOC(start, avail, loc, 10);  
    loc = start; 
    INSLOC(start, avail, loc, 20); 
    INSLOC(start, avail, loc, 30);  


    displayList(start);

    return 0;
}
