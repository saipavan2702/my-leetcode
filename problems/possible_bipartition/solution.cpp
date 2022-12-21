class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dis) {
        vector<int>adj[n+1];
        for(auto e:dis)
        {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        vector<int>vis(n+1,0);
        for(int i=1;i<=n;i++)
        {
            if(vis[i]==0)
            {
                queue<int>q;
                q.push(i);
                vis[i]=1;
                while(!q.empty())
                {
                  int x=q.front();
                  q.pop();
                  for(auto u:adj[x])
                  {
                    if(vis[u]==vis[x])
                    return 0;

                    if(vis[u]==0)
                    {
                        vis[u]=-vis[x];
                        q.push(u);
                    }
                  }
                }
            }
        }
        return 1;
    }
};