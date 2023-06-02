class Solution {
public:
    using ll=long long;
    int maximumDetonation(vector<vector<int>>& bob) {
        int n=bob.size();
        vector<int>adj[n];

        for(int i=0;i<n;i++){
            ll x=bob[i][0];
            ll y=bob[i][1];
            ll r=bob[i][2];

            for(int j=0;j<n;j++){
                if(i==j)
                continue;

                ll a=bob[j][0];
                ll b=bob[j][1];
                ll hyp=(x-a)*(x-a)+(y-b)*(y-b);

                if(hyp<=r*r)
                adj[i].push_back(j);
            }
        }

        auto bfs=[&](int u){
            queue<int>q;
            q.push(u);
            vector<bool>vis(n);

            int can=1;
            while(!q.empty()){
                int node=q.front();
                q.pop();

                vis[node]=1;
                for(auto v:adj[node]){
                    if(!vis[v]){
                        q.push(v);
                        can++;
                        vis[v]=1;
                    }
                }
            }
            return can;
        };

        int ans=0;
        for(int i=0;i<n;i++){
            ans=max(ans,bfs(i));
        }
        return ans;
        
    }
};