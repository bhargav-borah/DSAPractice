class Solution {
  public:
    bool isOperand(char ch) {
        return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <='9');
    }
    
    bool isOperator(char ch) {
        return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
    }
    
    int precedence(char ch) {
        if (ch == '^') return 3;
        else if (ch == '*' || ch == '/') return 2;
        else if (ch == '+' || ch == '-') return 1;
        return -1;
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
                st.push(ch);
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
};