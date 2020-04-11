// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// push(x) -- Push element x onto stack.
// pop() -- Removes the element on top of the stack.
// top() -- Get the top element.
// getMin() -- Retrieve the minimum element in the stack.

// https://leetcode.com/problems/min-stack/

class MinStack {
    stack<int> s1;
    stack<int> minVal;
public:
    /** initialize your data structure here. */
    MinStack() {
        
    }
    
    void push(int x) {
        s1.push(x);
        
        if(minVal.empty() || x <= minVal.top())
            minVal.push(x);         
    }
    
    void pop() {        
        if(minVal.top() == s1.top())
            minVal.pop();
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return minVal.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
