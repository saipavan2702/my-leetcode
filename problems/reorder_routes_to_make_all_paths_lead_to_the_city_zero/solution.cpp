class Solution {
public:
    int minReorder(int N, vector<vector<int>>& C) {
        vector<int>adj[N+1];
        
        for(auto c:C){
            adj[c[0]].push_back(c[1]);
            adj[c[1]].push_back(-c[0]);
        }
        vector<bool>vis(N+1,0);

        function<int(int)> recur=[&](int node){
            vis[node]=1;
            auto need=0;

            for(int u:adj[node]){
                if(!vis[abs(u)]){
                    need=need+recur(abs(u))+(u>0);
                }
            }
            return need;
        };
        return recur(0);
    }
};