#include <iostream>
using namespace std;

#define MAX 10

// Function to pop an item from the stack
void POP(int stack[], int &top, int &item) {
    // Step 1: Check if the stack is empty
    if (top == -1) {
        cout << "UNDERFLOW" << endl;
        return;
    }
    
    // Step 2: Assign the top element to ITEM
    item = stack[top];
    
    // Step 3: Decrease the top index by 1
    top--;
    
    // Step 4: Return
}

int main() {
    int stack[MAX], top = -1, item;
    
    // Sample input: Let's push some items onto the stack
    stack[++top] = 10;
    stack[++top] = 20;
    stack[++top] = 30;
    
    // Displaying the stack before popping
    cout << "Stack before popping: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;
    
    // Call the POP function
    POP(stack, top, item);
    
    // Display the popped item
    cout << "Popped item: " << item << endl;
    
    // Display the stack after popping
    cout << "Stack after popping: ";
    for (int i = 0; i <= top; i++) {
        cout << stack[i] << " ";
    }
    cout << endl;

    return 0;
}
/*
Stack before popping: 10 20 30 
Popped item: 30
Stack after popping: 10 20

*/