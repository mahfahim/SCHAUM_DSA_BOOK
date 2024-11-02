#include <iostream>
using namespace std;

// Define a Node structure for the linked list
struct Node {
    int data;       // Data of the node
    Node* next;     // Pointer to the next node
};

// Function to process each node (in this case, we simply print the data)
void process(int data) {
    cout << data << " ";
}

// Function to traverse the linked list
void traverseList(Node* start) {
    Node* ptr = start; // Step 1: Initialize pointer
    while (ptr != nullptr) { // Step 2: Loop while PTR is not NULL
        process(ptr->data); // Step 3: Apply PROCESS to data
        ptr = ptr->next; // Step 4: Move PTR to the next node
    }
}

int main() {
    // Creating a sample linked list: 10 -> 20 -> 30 -> 40
    Node* head = new Node{10, nullptr};
    head->next = new Node{20, nullptr};
    head->next->next = new Node{30, nullptr};
    head->next->next->next = new Node{40, nullptr};

    // Traverse the list and apply the PROCESS operation
    cout << "Linked List Elements: ";
    traverseList(head);
    cout << endl;

    // Clean up dynamically allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}
