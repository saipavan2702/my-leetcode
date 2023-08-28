class MyStack {
public:
    queue<int>q;
    queue<int>p;
    MyStack() {
        
    }
    
    void push(int x) {
        q.push(x);
    }
    
    int pop() {
        while(q.size()>1){
            p.push(q.front());
            q.pop();
        }
        int curr=q.front();
        q.pop();

        while(!p.empty()){
            q.push(p.front());
            p.pop();
        }
        return curr;
    }
    
    int top() {
        while(q.size()>1){
            p.push(q.front());
            q.pop();
        }
        int curr=q.front();
        q.pop();
        p.push(curr);

        while(!p.empty()){
            q.push(p.front());
            p.pop();
        }
        return curr;
    }
    
    bool empty() {
        return q.empty();
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