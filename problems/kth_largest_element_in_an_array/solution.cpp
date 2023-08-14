class Solution {
public:
    int findKthLargest(vector<int>& A, int k) {
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int &x:A){
            pq.push(x);
        }
        while(pq.size()>k) pq.pop();
        return pq.top();
    }
};