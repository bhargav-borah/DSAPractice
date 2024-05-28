class Solution {
public:
    bool isValid(string s) {
        stack<char> charStack;
        for (auto it: s) {
            if (it == '(' || it == '{' || it == '[') {
                charStack.push(it);
            }
            else {
                if (!charStack.empty() && (it == ')' && charStack.top() == '(') || (it == '}' && charStack.top() == '{') ||(it == ']' && charStack.top() == '[')) {
                    charStack.pop();
                }
                else {
                    return false;
                }
            }
        }

        return charStack.empty();
    }
};