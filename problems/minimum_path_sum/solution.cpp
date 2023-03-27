class Solution {
public:
    int dp[205][205];
    int recur(int u, int v, vector<vector<int>>& G){
        int n=G.size();
        int p=G[0].size();

        if(dp[u][v]!=-1)
        return dp[u][v];

        if(u==n-1 && v==p-1)
        return G[u][v];

        if(u<0 || u>=n || v<0 || v>=p)
            return 1e9;

        int a=G[u][v]+recur(u,v+1,G);
        int b=G[u][v]+recur(u+1,v,G);

        return dp[u][v]=min(a,b);
    }
    int minPathSum(vector<vector<int>>& G) {
        int n=G.size();
        int p=G[0].size();

        memset(dp,-1,sizeof(dp));
        return recur(0,0,G);
    }
};