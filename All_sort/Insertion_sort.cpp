// // Insertion sort in C++

// #include <iostream>
// using namespace std;

// // Function to print an array
// void printArray(int array[], int size) {
//   for (int i = 0; i < size; i++) {
//     cout << array[i] << " ";
//   }
//   cout << endl;
// }

// void insertionSort(int array[], int size) {
//   for (int step = 1; step < size; step++) {
//     int key = array[step];
//     int j = step - 1;

//     // Compare key with each element on the left of it until an element smaller than
//     // it is found.
//     // For descending order, change key<array[j] to key>array[j].
//     while (j >=0 && key < array[j]) {
//       array[j + 1] = array[j];
//       --j;
//     }
//     array[j + 1] = key;
//   }
// }

// // Driver code
// int main() {
//   int data[] = {9, 5, 1, 4, 3};
//   int size = sizeof(data) / sizeof(data[0]);
//   insertionSort(data, size);
//   cout << "Sorted array in ascending order:\n";
//   printArray(data, size);
// }



// // Time   Complexity	 
// // Best	     O(n)
// // Worst	 O(n2)
// // Average	O(n2)
// // Space Complexity	O(1)
// // Stability	Yes



#include <iostream>
using namespace std;

void insertionSort(int A[], int N) {
    for (int K = 1; K < N; K++) {
        int TEMP = A[K];
        int PTR = K - 1;
        
        // Move elements of A[0..K-1], that are greater than TEMP, to one position ahead of their current position
        while (PTR >= 0 && A[PTR] > TEMP) {
            A[PTR + 1] = A[PTR];
            PTR--;
        }
        
        // Insert the element at the correct position
        A[PTR + 1] = TEMP;
    }
}

int main() {
    int N;
    cout << "Enter the number of elements: ";
    cin >> N;
    
    int A[N];
    cout << "Enter the elements: ";
    for (int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    insertionSort(A, N);
    
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
