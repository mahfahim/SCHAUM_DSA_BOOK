#include <iostream>
using namespace std;

void QUICK(int A[], int N, int BEG, int END, int &LOC) {
    int LEFT = BEG;
    int RIGHT = END;
    LOC = BEG;

    while (true) {
        // Step 2: Scan from right to left
        while (A[LOC] <= A[RIGHT] && LOC != RIGHT) {
            RIGHT--;
        }

        if (LOC == RIGHT) {
            return;
        }

        if (A[LOC] > A[RIGHT]) {
            // Interchange A[LOC] and A[RIGHT]
            int TEMP = A[LOC];
            A[LOC] = A[RIGHT];
            A[RIGHT] = TEMP;
            LOC = RIGHT;
        }

        // Step 3: Scan from left to right
        while (A[LEFT] <= A[LOC] && LEFT != LOC) {
            LEFT++;
        }

        if (LOC == LEFT) {
            return;
        }

        if (A[LEFT] > A[LOC]) {
            // Interchange A[LEFT] and A[LOC]
            int TEMP = A[LOC];
            A[LOC] = A[LEFT];
            A[LEFT] = TEMP;
            LOC = LEFT;
        }
    }
}

// Function to display the array
void displayArray(int A[], int N) {
    for (int i = 0; i < N; i++) {
        cout << A[i] << " ";
    }
    cout << endl;
}

int main() {
 //   int A[] = {34, 7, 23, 32, 5, 62};
    int A[] = {44,33,11,55,77,90,40,60,99,22,88,66};
    int N = sizeof(A) / sizeof(A[0]);
    int BEG = 0;
    int END = N - 1;
    int LOC;

    cout << "Original Array: ";
    displayArray(A, N);

    QUICK(A, N, BEG, END, LOC);

    cout << "Array after QUICK procedure: ";
    displayArray(A, N);

    return 0;
}


/*
Original Array: 34 7 23 32 5 62
*/

/*
Array after QUICK procedure: 5 7 23 32 34 62
*/