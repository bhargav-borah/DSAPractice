#include <bits/stdc++.h>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

string postfixToInfix(string s) {
    stack<string> st;

    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if (isOperator(ch)) {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push("(" + op1 + string(1, ch) + op2 + ")");
        }
        else {
            st.push(string(1, ch));
        }
    }
    
    return st.top();
}

int main() {
    string postfix_expression = "ab+c*";
    cout << "Postfix Expression: " << postfix_expression << endl;
    cout << "Infix Expression: " << postfixToInfix(postfix_expression) << endl;
    
    return 0;
}