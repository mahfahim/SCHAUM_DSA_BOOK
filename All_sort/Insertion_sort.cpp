
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
