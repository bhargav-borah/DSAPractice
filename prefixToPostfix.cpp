#include <bits/stdc++.h>
using namespace std;

string reverseString(string s) {
    string newString = "";
    for (int i = s.length() - 1; i >= 0; i--) {
        newString += s[i];
    }
    
    return newString;
}

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

bool isOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9');
}

int precedence(char ch) {
    if (ch == '^') return 3;
    else if (ch == '*' || ch == '/') return 2;
    else if (ch == '+' || ch == '-') return 1;
    return -1;
}

string prefixToInfix(string s) {
    stack<string> st;
    s = reverseString(s);
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        if (isOperator(ch)) {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + string(1, ch) + op2 + ")");
        }
        else {
            st.push(string(1, ch));
        }
    }
    
    return st.top();
}

string infixToPostfix(string s) {
    stack<char> st;
    string postfix = "";
    
    for (int i = 0; i < s.length(); i++) {
        char ch = s[i];
        
        if (isOperand(ch)) {
            postfix += ch;
        }
        else if (isOperator(ch)) {
            if (st.empty()) st.push(ch);
            else if (precedence(ch) > precedence(st.top())) {
                st.push(ch);
            }
            else if (precedence(ch) <= precedence(st.top())) {
                while (!st.empty() && (precedence(ch) <= precedence(st.top()))) {
                    postfix += st.top();
                    st.pop();
                }
                st.push(ch);
            }
        }
        else if (ch == '(') {
            st.push('(');
        }
        else if (ch == ')') {
            while (!st.empty() && st.top() != '(') {
                postfix += st.top();
                st.pop();
            }
            st.pop();
        }
    }
    
    while (!st.empty()) {
        postfix += st.top();
        st.pop();
    }
    
    return postfix;
}

string prefixToPostfix(string s) {
    return infixToPostfix(prefixToInfix(s));
}

int main() {
    string prefix_expression = "*+AB-CD";
    cout << "Prefix Expression: " << prefix_expression << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix_expression) << endl;
    cout << "Postfix Expression: " << prefixToPostfix(prefix_expression) << endl;
    
    return 0;
}