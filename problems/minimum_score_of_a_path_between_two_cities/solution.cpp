class Solution {
public:
    int minScore(int n, vector<vector<int>>& E) {
        unordered_map<int,vector<pair<int,int>>>adj;
        for(auto e:E){
            adj[e[0]].push_back({e[1],e[2]});
            adj[e[1]].push_back({e[0],e[2]});
        }

        vector<int>vis(n+1,0);
        vis[1]=1;
        queue<int>q;
        q.push(1);
        int h=1e9;
        while(!q.empty()){
            
            int node=q.front();
            q.pop();

            for(auto x:adj[node]){
                int nxt=x.first;
                int dist=x.second;
                h=min(h,dist);

                if(!vis[nxt])
                q.push(nxt),vis[nxt]=1;
            }
        }
        return h;
    }
};