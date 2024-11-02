#include <iostream>
using namespace std;

// Function to implement the Towers of Hanoi algorithm
void TOWER(int N, char BEG, char AUX, char END) {
    // Base case: If there is only one disk
    if (N == 1) {
        cout << BEG << " -> " << END << endl; // Move disk from BEG to END
        return; // End the function
    }
    
    // Move N - 1 disks from BEG to AUX
    TOWER(N - 1, BEG, END, AUX);
    
    // Move the remaining disk from BEG to END
    cout << BEG << " -> " << END << endl; // Move disk from BEG to END
    
    // Move N - 1 disks from AUX to END
    TOWER(N - 1, AUX, BEG, END);
}

int main() {
    int N; // Number of disks
    //cout << "Enter the number of disks: ";
    cin >> N; // Taking user input for number of disks
    
    // Calling the TOWER function with initial pegs
    TOWER(N, 'A', 'B', 'C'); // A: BEG, B: AUX, C: END

    return 0; // End of program
}

/*
Enter the number of disks: 3

*/

/*
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C

*/