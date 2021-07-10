class MyQueue {
private:
    stack<int> in;
    stack<int> out;
    
public:
    /** Initialize your data structure here. */
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        in.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (out.empty()) {
            while (!in.empty()) {
                int tmp = in.top();
                in.pop();
                out.push(tmp);
            }
        }
        if (!out.empty()) {
            int tmp = out.top();
            out.pop();
            return tmp;
        }
        return NULL;
    }
    
    /** Get the front element. */
    int peek() {
        if (out.empty()) {
            while (!in.empty()) {
                int tmp = in.top();
                in.pop();
                out.push(tmp);
            }
        }
        if (!out.empty()) {
            int tmp = out.top();
            return tmp;
        }
        return NULL;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return (in.empty() && out.empty());
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */