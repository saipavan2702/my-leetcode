class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int n;
        n=arr.size();
        unordered_map<int,int>freq;
        for(auto x:arr)
        freq[x]++;
        
        priority_queue<pair<int,int>>pq;
        for(auto x:freq)
        pq.push({x.second,x.first});
        
        int cnt=0,w=0;
        while(!pq.empty())
        {
            w+=pq.top().first;
            cnt++;
            if(w>=n/2)
            return cnt;
            
            pq.pop();
        }
        return cnt;
    }
};