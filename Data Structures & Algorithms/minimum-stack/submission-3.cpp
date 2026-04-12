class MinStack {
private:
    stack<int> main;
    stack<int> minStack; /* storing the minimum at that point in time */
public:
    MinStack() {}
    
    void push(int val) {
        main.push(val);
        if (minStack.size() == 0) {
            minStack.push(val);
            return;
        }
        int minValue = min(minStack.top(), val);
        minStack.push(minValue);
    }
    
    void pop() {
        main.pop();
        minStack.pop();
    }
    
    int top() {
        return main.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};
