class MinStack {
public:
   stack<int>hi,get;

    MinStack() {
        
    }
    
    void push(int val) {
        hi.push(val);
        if(get.empty() || val<=getMin())
        get.push(val);
    }
    
    void pop() {
        if(hi.top()==get.top())get.pop();

        hi.pop();
    }
    
    int top() {
        return hi.top();
    }
    
    int getMin() {
        return get.top();
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