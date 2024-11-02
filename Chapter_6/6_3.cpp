#include <iostream>
#include <stack>
#include <sstream>
#include <string>

using namespace std;

int evaluatePostfix(const string& expression) 
{
    stack<int> s;
    stringstream ss(expression);
    string token;
    
    // Scan each token in the postfix expression
    while (ss >> token) 
    {
        if (isdigit(token[0]))
        {
            // If the token is an operand, push it to the stack
            s.push(stoi(token));
        } else 
        {
            // If the token is an operator, pop two elements from the stack
            int A = s.top(); s.pop();
            int B = s.top(); s.pop();
            int result;
            
            // Perform the operation
            switch (token[0]) 
            {
                case '+':
                    result = B + A;
                    break;
                case '-':
                    result = B - A;
                    break;
                case '*':
                    result = B * A;
                    break;
                case '/':
                    result = B / A;
                    break;
                default:
                    cout << "Invalid operator encountered!" << endl;
                    return -1;
            }
            
            // Push the result back onto the stack
            s.push(result);
        }
    }
    
    // The final result will be the last element in the stack
    return s.top();
}

int main() {
    string expression = "5 6 2 + * 12 4 / -";
    int result = evaluatePostfix(expression);
    cout << "The result of the postfix expression is: " << result << endl;
    
    return 0;
}
