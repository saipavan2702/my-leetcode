class Solution {
public:
    vector<int> topKFrequent(vector<int>& A, int k) {
        unordered_map<int,int>dict;

        for(int i:A)
        dict[i]++;

        priority_queue<pair<int,int>>pq;
        for(auto [x,y]:dict){
            pq.push({y,x});
        }

        vector<int>ans;
        while(k--){
            int x=pq.top().second;
            pq.pop();
            ans.push_back(x);
        }
        return ans;
    }
};