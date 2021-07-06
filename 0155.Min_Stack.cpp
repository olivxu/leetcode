/*
 * 踩坑记录：
 *        1. minTack.empty()
 *        2. val <= minStack.top() 这里要加上等于
 */
 
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> myStack;
    stack<int> minStack; 
    
    MinStack() {
        
    }
    
    void push(int val) {
        myStack.push(val);
        if (minStack.empty() || val <= minStack.top())
            minStack.push(val);      
    }
    
    void pop() {
        if (myStack.top() == minStack.top()) 
            minStack.pop();
        myStack.pop();
    }
    
    int top() {
        return myStack.top();
    }
    
    int getMin() {
        return minStack.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */