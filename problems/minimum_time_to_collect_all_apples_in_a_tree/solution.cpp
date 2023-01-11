class Solution {
public:
    int dfs(vector<bool>&A, vector<int>adj[], int node, int c, vector<bool>&vis) {
        if(vis[node])
        return 0;

        vis[node]=1;
        int d=0;
        for(int u:adj[node]){
            d+=dfs(A,adj,u,1,vis);
        }
        if(d==0 && !A[node])
        return 0;

        return d+c;
    }
    int minTime(int n, vector<vector<int>>&E, vector<bool>&A) {
        vector<int>adj[n];
        for(int i=0;i<E.size();i++){
            adj[E[i][0]].push_back(E[i][1]);
            adj[E[i][1]].push_back(E[i][0]);
        }
        vector<bool>vis(n,0);
        return 2*dfs(A,adj,0,0,vis);
    }
};