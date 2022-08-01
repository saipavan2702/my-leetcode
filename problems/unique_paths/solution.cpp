class Solution {
public:
    int dfs(int m,int n,int st,int end,vector<vector<int>>&dp)
    {
        if(st==m-1 and end==n-1)
         return 1;
        if(st>=m or end>=n)
         return 0;
        if(dp[st][end]!=-1)
        return dp[st][end];
        
        return dp[st][end]=dfs(m,n,st+1,end,dp)+dfs(m,n,st,end+1,dp);
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        int cnt=dfs(m,n,0,0,dp);
        return cnt;
    }
};