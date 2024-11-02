#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

// Function to find the location of the first node containing ITEM
Node* findItem(Node* start, int item) {
    Node* ptr = start;
    while (ptr != nullptr) {
        if (ptr->data == item) {
            return ptr; // Location found
        }
        ptr = ptr->next;
    }
    return nullptr; // Location not found
}

// Helper function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

// Helper function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    // Sample input: creating a linked list with nodes
    Node* start = createNode(10);
    start->next = createNode(20);
    start->next->next = createNode(30);
    start->next->next->next = createNode(40);

    cout << "Linked list: ";
    printList(start);

    int item = 30;
    Node* loc = findItem(start, item);

    // Output
    if (loc != nullptr) {
        cout << "Item " << item << " found at location: " << loc << endl;
    } else {
        cout << "Item " << item << " not found in the list." << endl;
    }

    return 0;
}
