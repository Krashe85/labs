#include<iostream>
#include<stack>

using namespace std;


bool bracketBalance(string exp) {
    stack<char> stack;
    char top;
    for (int i = 0; i < exp.length(); i++) {
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[')
            stack.push(exp[i]);
        else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            top = stack.top();

            if (stack.empty()) {
                return false;
            }

            if (top == '(' && exp[i] != ')' || top == '[' && exp[i] != ']' || top == '{' && exp[i] != '}') {
                return false;
            } else
                stack.pop();
        }
    }
    return stack.empty();
}

int main() {
    string expression;
    cout << "Enter:  ";
    cin >> expression;
    if (bracketBalance(expression))
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";
}