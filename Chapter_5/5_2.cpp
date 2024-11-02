#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

// Function to search for ITEM in the linked list starting from START
Node* SEARCH(Node* START, int ITEM) {
    Node* PTR = START;  // Step 1: Set PTR = START
    while (PTR != nullptr) {  // Step 2: Repeat while PTR is not NULL
        if (PTR->info == ITEM) {  // Step 3: If ITEM is found
            return PTR;  // Set LOC = PTR and exit
        }
        PTR = PTR->link;  // Move PTR to the next node
    }
    return nullptr;  // Step 4: Search is unsuccessful, return NULL
}

// Function to add a node at the beginning of the linked list
void insert(Node*& START, int data) {
    Node* newNode = new Node();
    newNode->info = data;
    newNode->link = START;
    START = newNode;
}

// Function to display the linked list
void display(Node* START) {
    Node* PTR = START;
    while (PTR != nullptr) {
        cout << PTR->info << " -> ";
        PTR = PTR->link;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* START = nullptr;
    
    // Sample input: Creating a linked list
    insert(START, 10);
    insert(START, 20);
    insert(START, 30);
    insert(START, 40);
    
    cout << "Linked List: ";
    display(START);
    
    int ITEM;
    cout << "Enter the item to search: ";
    cin >> ITEM;
    
    // Searching for the ITEM
    Node* LOC = SEARCH(START, ITEM);
    
    if (LOC != nullptr) {
        cout << "Item " << ITEM << " found at node address: " << LOC << endl;
    } else {
        cout << "Item " << ITEM << " not found in the list." << endl;
    }
    
    return 0;
}
//40 -> 30 -> 20 -> 10 -> NULL
// Item 30 found at node address: 0x600000000xxxx
