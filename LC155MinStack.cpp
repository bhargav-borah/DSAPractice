class MinStack {
public:
    // Methods pop, top and getMin operations will always be called on non-empty stacks.
    stack<int> s;
    int mini = INT_MAX;

    MinStack() {
        
    }
    
    void push(int val) {
        if (val <= mini) {
            s.push(mini);
            mini = val;
        }
        s.push(val);
    }
    
    void pop() {
        if (s.top() == mini) {
            s.pop();
            mini = s.top();
            s.pop();
            return;
        }
        s.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        return mini;
    }
};

