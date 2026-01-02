class MinStack {
public:
    stack<int> st1;
    stack<int> st2;

    MinStack() {
        st2.push(INT_MAX);
    }
    
    void push(int val) {
        st1.push(val);
        st2.push(min(val, st2.top()));
    }
    
    void pop() {
        st1.pop();
        st2.pop();
    }
    
    int top() {
        return st1.top();
    }
    
    int getMin() {
        return st2.top();
    }
};
