#include <iostream>
#include <stack>
using namespace std;

// Function to partition the array
int partition(int A[], int beg, int end) {
    int pivot = A[end];
    int i = beg - 1;
    
    for (int j = beg; j < end; j++) {
        if (A[j] <= pivot) {
            i++;
            swap(A[i], A[j]);
        }
    }
    swap(A[i + 1], A[end]);
    return (i + 1);
}

// Iterative QuickSort function
void quickSort(int A[], int N) {
    stack<int> lower, upper;
    
    // Step 2: Push initial boundaries onto the stacks
    if (N > 1) {
        lower.push(0);
        upper.push(N - 1);
    }

    // Step 3: Repeat until the stack is empty
    while (!lower.empty()) {
        int beg = lower.top();
        int end = upper.top();
        lower.pop();
        upper.pop();
        
        // Step 4: Partition the array
        int loc = partition(A, beg, end);

        // Step 6: Push left sublist if it has 2 or more elements
        if (beg < loc - 1) {
            lower.push(beg);
            upper.push(loc - 1);
        }
        
        // Step 7: Push right sublist if it has 2 or more elements
        if (loc + 1 < end) {
            lower.push(loc + 1);
            upper.push(end);
        }
    }
}

// Utility function to print the array
void printArray(int A[], int size) {
    for (int i = 0; i < size; i++)
        cout << A[i] << " ";
    cout << endl;
}

int main() {
    int A[] = {44, 33, 11, 55, 77, 90, 40, 60, 99, 22, 88, 66};
    int N = sizeof(A) / sizeof(A[0]);

    cout << "Original array: ";
    printArray(A, N);

    quickSort(A, N);

    cout << "Sorted array: ";
    printArray(A, N);

    return 0;
}
/*
Original array: 44 33 11 55 77 90 40 60 99 22 88 66
Sorted array: 11 22 33 40 44 55 60 66 77 88 90 99
  
*/