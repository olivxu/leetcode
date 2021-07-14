class MyStack {
private:
    queue<int> one;
    queue<int> two;    
    
public:
    /** Initialize your data structure here. */
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        if (!one.empty()) {
            while (!one.empty()) {
                int tmp = one.front();
                one.pop();
                two.push(tmp);
            }
            one.push(x);
            while (!two.empty()) {
                int tmp = two.front();
                two.pop();
                one.push(tmp);
            }
        }
        else {
            one.push(x);
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        if (!one.empty()) {
            int tmp = one.front();
            one.pop();
            return tmp;
        }
        return NULL;
    }
    
    /** Get the top element. */
    int top() {
        if (!one.empty()) {
            int tmp = one.front();
            return tmp;
        }
        return NULL;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return one.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */