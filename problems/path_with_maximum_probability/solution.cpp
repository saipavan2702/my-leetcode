class Solution {
public:
    using pD=pair<int,double>;

    double maxProbability(int n,vector<vector<int>>& E,vector<double>& sp,int st,int en) {
        vector<pD>adj[n+1];

        for(int i=0;i<E.size();i++){
            adj[E[i][0]].push_back({E[i][1],sp[i]});
            adj[E[i][1]].push_back({E[i][0],sp[i]});
        }

        vector<bool>vis(n,false);
        
        double ans=1e-5;
        function<void(int,double)>recur=[&](int u, double cn){
            if(vis[u])return;
            if(u==en){    
                ans=max(ans,cn);
                return;
            }

            vis[u]=true;
            for(auto node:adj[u]){
                if(!vis[node.first] && cn*node.second>=ans){
                    recur(node.first,cn*node.second);
                }
            }
            vis[u]=false;
        };
        recur(st,1.0);
        return ans;
    }
};