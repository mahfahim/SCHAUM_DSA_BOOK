#include <iostream>
#define N 5 // Define the maximum size of the queue

using namespace std;

void QINSERT(int queue[], int &front, int &rear, int item) {
    // Step 1: Check if the queue is full
    if ((front == 0 && rear == N - 1) || (front == rear + 1)) {
        cout << "OVERFLOW" << endl;
        return;
    }
    
    // Step 2: Find new value of REAR
    if (front == -1) {
        // Queue is initially empty
        front = 0;
        rear = 0;
    } else if (rear == N - 1) {
        rear = 0; // Wrap around
    } else {
        rear = rear + 1;
    }
    
    // Step 3: Insert new element
    queue[rear] = item;
    
    // Step 4: Return
}

void displayQueue(int queue[], int front, int rear) {
    if (front == -1) {
        cout << "Queue is empty" << endl;
        return;
    }
    
    cout << "Queue elements: ";
    int i = front;
    while (true) {
        cout << queue[i] << " ";
        if (i == rear) break;
        i = (i + 1) % N; // Move to the next index, wrap around if necessary
    }
    cout << endl;
}

int main() {
    int queue[N];
    int front = -1, rear = -1;
    
    // Sample input
    QINSERT(queue, front, rear, 10);
    QINSERT(queue, front, rear, 20);
    QINSERT(queue, front, rear, 30);
    QINSERT(queue, front, rear, 40);
    QINSERT(queue, front, rear, 50);
    QINSERT(queue, front, rear, 60); // This should display "OVERFLOW"
    
    // Display queue
    displayQueue(queue, front, rear);
    
    return 0;
}
/*
OVERFLOW
Queue elements: 10 20 30 40 50

*/