class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>&E, int S, int D, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto x:E){
            adj[x[0]].push_back({x[1],x[2]});
        }
        queue<pair<int,int>>q;
        q.push({S,0});
        
        vector<int>cst(n,INT_MAX);
        while(!q.empty() && k>=0) {
            int len=q.size();
            while(len--) {

                auto p=q.front();
                q.pop();
                int z=p.first;
                int d=p.second;

                for(auto [u,v]:adj[z]) {

                    if(d+v<cst[u]) {
                        cst[u]=d+v;
                        q.push({u,cst[u]});
                    }
                }
            }
            k--;
        }
        return cst[D]==INT_MAX?-1:cst[D];
    }
};