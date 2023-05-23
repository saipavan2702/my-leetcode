class KthLargest {
public:
    priority_queue<int,vector<int>,greater<int>>pq;
    int c;
    KthLargest(int k, vector<int>& nums) {
        for(auto i:nums){
            pq.push(i);
        }
        c=k;
    }
    
    int add(int val) {
        pq.push(val);
        while(pq.size()>c){
            pq.pop();
        }
        return pq.top();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */