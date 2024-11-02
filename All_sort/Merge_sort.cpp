#include <iostream>
using namespace std;

// Merge function that merges two subarrays
void merge(int A[], int LB1, int UB1, int LB2, int UB2, int B[], int LB) {
    int i = LB1, j = LB2, k = LB;
    
    // Merge the two subarrays into B
    while (i <= UB1 && j <= UB2) {
        if (A[i] <= A[j]) {
            B[k++] = A[i++];
        } else {
            B[k++] = A[j++];
        }
    }
    
    // Copy remaining elements from the first subarray, if any
    while (i <= UB1) {
        B[k++] = A[i++];
    }
    
    // Copy remaining elements from the second subarray, if any
    while (j <= UB2) {
        B[k++] = A[j++];
    }
}

// MERGEPASS function to merge subarrays
void mergePass(int A[], int N, int L, int B[]) {
    int Q = N / (2 * L);
    int S = 2 * L * Q;
    int R = N - S;
    
    // Use the merge function to merge pairs of subarrays
    for (int J = 0; J < Q; J++) {
        int LB = 1 + (2 * J) * L;
        merge(A, LB - 1, LB + L - 2, LB + L - 1, LB + 2 * L - 2, B, LB - 1);
    }
    
    // Handle the last subarray if it has fewer than L elements
    if (R <= L) {
        for (int J = 0; J < R; J++) {
            B[S + J] = A[S + J];
        }
    } else {
        merge(A, S, S + L - 1, S + L, N - 1, B, S);
    }
}

// Merge Sort function
void mergeSort(int A[], int N) {
    int* B = new int[N];
    int L = 1;
    
    // Repeat until L is greater than or equal to N
    while (L < N) {
        mergePass(A, N, L, B);
        mergePass(B, N, 2 * L, A);
        L = 2 * L;
    }
    
    delete[] B;
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
    
    mergeSort(A, N);
    
    cout << "Sorted array: ";
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
    
    return 0;
}
