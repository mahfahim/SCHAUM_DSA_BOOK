#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to check precedence of operators
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    if (op == '^') return 3;
    return 0;
}

// Function to check if the character is an operator
bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^';
}

// Function to convert infix expression to postfix expression
string convertToPostfix(string Q) {
    stack<char> s;
    string P = "";
    s.push('(');
    Q += ')';

    for (char c : Q) {
        // Step 3: If an operand is encountered, add to P
        if (isalnum(c)) {
            P += c;
        }
        // Step 4: If a left parenthesis is encountered, push it onto STACK
        else if (c == '(') {
            s.push(c);
        }
        // Step 5: If an operator is encountered
        else if (isOperator(c)) {
            while (!s.empty() && isOperator(s.top()) && precedence(s.top()) >= precedence(c)) {
                P += s.top();
                s.pop();
            }
            s.push(c);
        }
        // Step 6: If a right parenthesis is encountered
        else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                P += s.top();
                s.pop();
            }
            s.pop(); // Remove the left parenthesis
        }
    }

    return P;
}

// Main function to test the algorithm
int main() {
    string Q;
   // cout << "Enter an infix expression: ";
    cin >> Q;//      A+B*(C^D-E)^(F+G*H)-I

    string postfix = convertToPostfix(Q);
    cout << "Postfix expression: " << postfix << endl;
     //   ABCD^E-FGH*+^*+I-

    return 0;
}
