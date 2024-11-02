#include <iostream>
using namespace std;

int factorial(int N) {
    int FACT = 1; // Step 2: Initialize FACT
    if (N == 0) {
        FACT = 1; // Step 1: If N is 0, set FACT to 1
    } else {
        for (int K = 1; K <= N; K++) {
            FACT *= K; // Step 3: Multiply FACT by K in the loop
        }
    }
    return FACT; // Step 4: Return the result
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    
    int result = factorial(N);
    cout << "Factorial of " << N << " is: " << result << endl;
    
    return 0;
}

// Enter a number: 5
// Factorial of 5 is: 120
