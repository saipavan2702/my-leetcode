class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<int>adj[n];
        for(auto e:edges)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<int>q;
        q.push(src);

        vector<int>vis(n);
        vis[src]=1;
        while(!q.empty())
        {
           int curr=q.front();
           q.pop();
           if(curr==dest)
               return 1;

           for(auto u:adj[curr])
           {
               if(!vis[u])
               vis[u]=1,q.push(u);
           }
        }
        return 0;
    }
};