class Solution {
public:
    int maxStarSum(vector<int>& val, vector<vector<int>>&e, int k) {
        int n;
        n=val.size();
        
        vector<int>adj[n];
        for(auto x:e)
        {
            adj[x[0]].push_back(x[1]);
            adj[x[1]].push_back(x[0]);
        }
        
        int req=-1e9+7;
        for(int i=0;i<n;i++)
        {
            priority_queue<int,vector<int>,greater<int>>pq;
            
            int ret=val[i];
            for(auto x:adj[i])
            {
                pq.push(val[x]);
                if(pq.size()>k)
                    pq.pop();
            }
            
            while(!pq.empty())
            {
                if(pq.top()>0)
                ret+=pq.top();
                
                pq.pop();
            }
            req=max(req,ret);
        }
        return req;
    }
};