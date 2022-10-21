class Solution {
public:
    bool validPath(int n, vector<vector<int>>&edges, int s, int d) {
        if(s==d)
        return 1;
        
        vector<int>adj[n+1];
        for(auto x:edges)
        {
         adj[x[0]].push_back(x[1]);
         adj[x[1]].push_back(x[0]);
        }
        
        queue<int>q;
        vector<bool>vis(n+1,0);
        vis[s]=1;
        q.push(s);
        
        while(!q.empty())
        {
            int r=q.front();
            q.pop();
            
            if(r==d)
            return 1;
            
            for(auto x:adj[r])
            {
                if(!vis[x])
                {
                    vis[x]=1;
                    q.push(x);
                }
            }
        }
        return 0;
    }
};