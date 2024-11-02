#include <iostream>
using namespace std;

int factorial(int n) {
    // Step 1: If N = 0, return 1
    if (n == 0) {
        return 1;
    }
    // Step 2: Recursive call
    int fact = factorial(n - 1);
    // Step 3: Set FACT = N * FACT
    return n * fact;
}

int main() {
    int n;
    cout << "Enter a number to find its factorial: ";
    cin >> n;

    // Call the factorial function and store the result
    int result = factorial(n);

    // Output the result
    cout << "Factorial of " << n << " is: " << result << endl;

    return 0;
}

// Enter a number to find its factorial: 5
// Factorial of 5 is: 120
