class MyQueue {
public:
    stack<int>in;
    MyQueue() {
        
    }
    
    void push(int x) {
        stack<int>out;

        while(!in.empty())
        out.push(in.top()),in.pop();

        out.push(x);

        while(!out.empty())
        in.push(out.top()),out.pop();

    }
    int pop() {
        int ans=in.top();
        in.pop();
        return ans;
    }
    
    int peek() {
        return in.top();
    }
    
    bool empty() {
        return in.empty();
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