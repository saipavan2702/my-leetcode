class Solution {
public:
    vector<int> numberGame(vector<int>& A) {
        priority_queue<int, vector<int>, greater<int>>pq;
        for(auto x:A) pq.push(x);
        
        vector<int>ans;
        while(!pq.empty()){
            int x=pq.top();pq.pop();
            int y=pq.top();pq.pop();
            ans.push_back(y);
            ans.push_back(x);
        }
        return ans;
    }
};