#include <iostream>
using namespace std;

void FIBONACCI(int &FIB, int N) {
    if (N == 0 || N == 1) {
         FIB = N;
        return;
    }
    
    int FIBA, FIBB;
    
    FIBONACCI(FIBA, N - 1);
    FIBONACCI(FIBB, N - 2);
    
    FIB = FIBA + FIBB;
}

int main() {
    int N;
    cout << "Enter a number: ";
    cin >> N;
    
    int FIB;
    FIBONACCI(FIB, N);
    
    cout << "Fibonacci of " << N << " is: " << FIB << endl;
    
    return 0;
}

// Enter a number: 10
// Fibonacci of 5 is: 55
