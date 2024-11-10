#include <iostream> 
#include <stack> 
#include <string> 
using namespace std; 
 
// Function to determine precedence of operators 
int precedence(char op) { 
    if(op == '+' || op == '-') { 
        return 1; 
    } else if(op == '*' || op == '/') { 
        return 2; 
    } else if(op == '^') { 
        return 3; 
    } 
    return 0; 
} 
 
// Function to check if a character is an operator 
bool isOperator(char c) { 
    return c == '+' || c == '-' || c == '*' || c == '/' || c == '^'; 
} 
 
// Function to convert infix expression to postfix 
string infixToPostfix(const string& infix) { 
    stack<char> s; 
    string postfix = ""; 
 
    for(char c : infix) { 
        // If the character is an operand, add it to the postfix expression 
        if(isalnum(c)) { 
            postfix += c; 
        } 
        // If the character is '(', push it onto the stack 
        else if(c == '(') { 
            s.push(c); 
        } 
        // If the character is ')', pop from stack until '(' is found 
        else if(c == ')') { 
            while(!s.empty() && s.top() != '(') { 
                postfix += s.top(); 
                s.pop(); 
            } 
            s.pop();  // Pop '(' 
        } 
        // If the character is an operator 
        else if(isOperator(c)) { 
            while(!s.empty() && precedence(s.top()) >= precedence(c)) { 
                postfix += s.top(); 
                s.pop(); 

            } 
            s.push(c); 
        } 
    } 
 
    // Pop all the remaining operators from the stack 
    while(!s.empty()) { 
        postfix += s.top(); 
        s.pop(); 
    } 
 
    return postfix; 
} 
 
int main() { 
    string infix; 
    cout << "Enter an infix expression: "; 
    cin >> infix; 
    cout << "Postfix expression: " << infixToPostfix(infix) << endl; 
    return 0; 
} 