#include <iostream>
using namespace std;

struct Node {
    int info;
    Node* link;
};

// Function to delete the first occurrence of ITEM in the list
void DELETE(Node*& start, Node*& avail, int item, bool& flag) {
    // Step 1: Check if the list is empty
    if (start == nullptr) {
        flag = false;
        return;
    }

    // Step 2: Check if ITEM is in the first node
    if (start->info == item) {
        Node* ptr = start;
        start = start->link;
        ptr->link = avail;
        avail = ptr;
        flag = true;
        return;
    }

    // Step 3: Initialize pointers
    Node* ptr = start->link;
    Node* save = start;

    // Step 4: Traverse the list to find ITEM
    while (ptr != nullptr) {
        // Step 5: If ITEM is found
        if (ptr->info == item) {
            save->link = ptr->link;
            ptr->link = avail;
            avail = ptr;
            flag = true;
            return;
        }
        // Step 6: Update pointers
        save = ptr;
        ptr = ptr->link;
    }

    // Step 7: If ITEM was not found, set FLAG to false
    flag = false;
}

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = new Node();
    newNode->info = data;
    newNode->link = nullptr;
    return newNode;
}

// Function to display the linked list
void displayList(Node* start) {
    Node* temp = start;
    while (temp != nullptr) {
        cout << temp->info << " ";
        temp = temp->link;
    }
    cout << endl;
}

int main() {
    // Sample input
    Node* start = createNode(10);
    start->link = createNode(20);
    start->link->link = createNode(30);
    start->link->link->link = createNode(40);

    Node* avail = nullptr;
    int item = 20;
    bool flag;

    cout << "Original list: ";
    displayList(start);

    // Delete the first occurrence of item
    DELETE(start, avail, item, flag);

    cout << "After deleting " << item << ": ";
    displayList(start);

    if (flag) {
        cout << "Item " << item << " was successfully deleted." << endl;
    } else {
        cout << "Item " << item << " was not found in the list." << endl;
    }

    return 0;
}
