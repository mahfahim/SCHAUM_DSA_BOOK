#include <iostream>
using namespace std;

const int MAXSTK = 5; // Maximum size of the stack

// Function to push an item onto the stack
void PUSH(int STACK[], int &TOP, int ITEM) {
    // Step 1: Check if the stack is already full
    if (TOP == MAXSTK - 1) {
        cout << "OVERFLOW" << endl;
        return;
    }
    // Step 2: Increase TOP by 1
    TOP = TOP + 1;
    // Step 3: Add ITEM to the stack
    STACK[TOP] = ITEM;
    // Step 4: Print the item that has been added
    cout << "Item " << ITEM << " pushed to stack and top "<<TOP<< endl;
}

int main() {
    int STACK[MAXSTK]; // Define stack with a maximum size
    int TOP = -1;      // Initialize TOP to -1 (indicating an empty stack)
    
    // Sample inputs
    PUSH(STACK, TOP, 10);
    PUSH(STACK, TOP, 20);
    PUSH(STACK, TOP, 30);
    PUSH(STACK, TOP, 40);
    PUSH(STACK, TOP, 50);
    PUSH(STACK, TOP, 60); // This will cause an overflow

    // Display the content of the stack
    cout << "Stack content: ";
    for (int i = 0; i <= TOP; i++) {
        cout << STACK[i] << " ";
    }
    cout << endl;
    
    return 0;
}

/*
Item 10 pushed to stack.
Item 20 pushed to stack.
Item 30 pushed to stack.
Item 40 pushed to stack.
Item 50 pushed to stack.
OVERFLOW
Stack content: 10 20 30 40 50

*/