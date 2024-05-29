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

int main() {
    string prefix_expression = "*+AB-CD";
    cout << "Prefix Expression: " << prefix_expression << endl;
    cout << "Infix Expression: " << prefixToInfix(prefix_expression) << endl;
    
    return 0;
}