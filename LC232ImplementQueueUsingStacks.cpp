class MyQueue {
public:
    stack<int> s1, s2;

    MyQueue() {
        
    }
    
    void push(int x) {

        while (!s1.empty()) {
            s2.push(s1.top());
            s1.pop();
        }

        s1.push(x);

        while (!s2.empty()) {
            s1.push(s2.top());
            s2.pop();
        }
    }
    
    int pop() {
        int n = s1.top();
        s1.pop();

        return n;
    }
    
    int peek() {
        return s1.top();
    }
    
    bool empty() {
        return s1.empty();
    }
};