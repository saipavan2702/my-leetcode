class Solution {
public:
    long long h=0;
    int recur(vector<vector<int>>&adj, int S, int prev, int node) {
        
        int cnt=1;
        for(auto x:adj[node]){
            if(x==prev) 
            continue;

            cnt+=recur(adj,S,node,x);
        }
        
        if(node!=0)
        h+=ceil(cnt*1.0/S);

        return cnt;
    }

    long long minimumFuelCost(vector<vector<int>>& E, int S) {
        int n=E.size();

        vector<vector<int>>adj(n+1);
        for(auto&e:E) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        recur(adj,S,-1,0);
        
        return h;
    }
};