#include <iostream>
#include <stack>

using namespace std;

// Define a structure to hold the state of the function call
struct State {
    int N;
    char BEG, AUX, END;
    int ADD;
};

void TOWER(int N, char BEG, char AUX, char END) {
    stack<State> s;
    int TOP = -1;
    
    // Step 0: Set TOP := NULL
    if (N > 0) {
        // Step 1: If N = 1, then:
        while (true) {
            if (N == 1) {
                cout << BEG << " -> " << END << endl; // (a) Write: BEG—END
                if (TOP == -1) return; // (a) If TOP := NULL, then: Return.
                
                // Step 5: Translation of "Return"
                // (b) Restore top values on stacks
                State restoredState = s.top();
                s.pop();
                N = restoredState.N;
                BEG = restoredState.BEG;
                AUX = restoredState.AUX;
                END = restoredState.END;
                int ADD = restoredState.ADD;
                TOP--;
                
                // (c) Go to Step ADD
                if (ADD == 3) {
                    // Step 3: Write: BEG—END.
                    cout << BEG << " -> " << END << endl;
                    
                    // Step 4: Translation of "Call TOWER(N - 1, AUX, BEG, END)"
                    // (a) Push current values and new return address onto stacks
                    TOP++;
                    s.push({N, BEG, AUX, END, 5});
                    
                    // (b) Reset parameters
                    N = N - 1;
                    char temp = BEG;
                    BEG = AUX;
                    AUX = temp;
                    continue; // Go to Step 1
                }
            } else {
                // Step 2: Translation of "Call TOWER(N - 1, BEG, END, AUX)"
                // (a) Push current values and new return address onto stacks
                TOP++;
                s.push({N, BEG, AUX, END, 3});
                
                // (b) Reset parameters
                N = N - 1;
                char temp = END;
                END = AUX;
                AUX = temp;
            }
        }
    }
}

int main() {
    int N;
    cout << "Enter the number of disks: ";
    cin >> N;
    TOWER(N, 'A', 'B', 'C');
    return 0;
}

/*
Enter the number of disks: 3
A -> C
A -> B
C -> B
A -> C
B -> A
B -> C
A -> C

*/