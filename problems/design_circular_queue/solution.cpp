class MyCircularQueue {
public:
    vector<int>data;
    int tail,head;
    bool reset;
     MyCircularQueue(int k) {
        data.resize(k);
        head = 0;
        tail = 0;
        reset = true;
    }
    
    /** Insert an element into the circular queue. Return true if the operation is successful. */
    bool enQueue(int value) {
        if (isFull()) return false;
        // update the reset value when first enqueue happens
        if (head == tail && reset) reset = false;
        data[tail] = value;
        tail = (tail + 1) % data.size();
        return true;
    }
    
    /** Delete an element from the circular queue. Return true if the operation is successful. */
    bool deQueue() {
        if (isEmpty()) return false;
        head = (head + 1) % data.size();
        // update the reset value when last dequeue happens
        if (head == tail && !reset) reset = true; 
        return true;
    }
    
    /** Get the front item from the queue. */
    int Front() {
        if (isEmpty()) return -1;
        return data[head];
    }
    
    /** Get the last item from the queue. */
    int Rear() {
        if (isEmpty()) return -1;
        return data[(tail + data.size() - 1) % data.size()];
    }
    
    /** Checks whether the circular queue is empty or not. */
    bool isEmpty() {
        if (tail == head && reset) return true;
        return false;
    }
    
    /** Checks whether the circular queue is full or not. */
    bool isFull() {
        if (tail == head && !reset) return true;
        return false;
    }
//     MyCircularQueue(int k) {
//         res.resize(k);
//         i=0;
//         j=0;
//         flag=1;
//     }
    
//     bool enQueue(int value) {
//         if(isFull())
//         return 0;
        
//         if(i==j and flag)
//         flag=0;
        
//         res[j]=value;
//         j=(j+1)%res.size();
        
//         return 1;
//     }
    
//     bool deQueue() {
//         if(isEmpty())
//         return 0;
        
//         i=(i+1)%res.size();
        
//         if(i==j and !flag)
//         flag=0;
        
//         return 1;
//     }
    
//     int Front() {
//         if(isEmpty())
//         return -1;
        
//         return res[i];
//     }
    
//     int Rear() {
//         if(isEmpty())
//         return -1;
        
//         return res[(j+res.size()-1)%res.size()];
//     }
    
//     bool isEmpty() {
//         if(i==j and flag)
//         return 1;
        
//         return 0;
//     }
    
//     bool isFull() {
//         if(i==j and !flag)
//         return 1;
        
//         return 0;
//     }
   
};

/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */