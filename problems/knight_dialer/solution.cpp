class Solution {
public:
    const int MOD=1e9+7;
    int knightDialer(int n) {

        vector<vector<int>> adj={
            {4, 6},{6, 8},{7, 9},{4, 8}, {3, 9, 0},
            {}, {1, 7, 0},{2, 6}, {3, 1},{2,4}
        };

        int dp[10][5005];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int u,int n){
            if(n==1) return 1;
            if(u==5) return 0;
            if(dp[u][n]!=-1) return dp[u][n];

            int ans=0;
            for(int node:adj[u]) {
                ans=(ans+recur(node,n-1))%MOD;
            }
            return dp[u][n]=ans;
        };

        int ans=0;
        for(int i=0;i<10;i++){
            ans=(ans+recur(i,n))%MOD;
        }
        return ans;
    }
};