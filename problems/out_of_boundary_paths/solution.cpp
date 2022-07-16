class Solution {
public:
    long long int dp[55][55][55];
    int path(int m,int n,int move,int sr,int sc)
    {
        if(move<0)
        return 0;
    
        if(sr>=m or sc>=n or sr<0 or sc<0)
        {
            return 1; 
        }
        if( dp[sr][sc][move] != -1)
        return dp[sr][sc][move];
        
        long long int u=path(m,n,move-1,sr-1,sc)%1000000007;
        long long int r=path(m,n,move-1,sr,sc+1)%1000000007;
        long long int d=path(m,n,move-1,sr+1,sc)%1000000007;
        long long int l=path(m,n,move-1,sr,sc-1)%1000000007;
        
        dp[sr][sc][move]=(u+r+d+l)%1000000007;
        return dp[sr][sc][move];
    }
    int findPaths(int m, int n, int move, int sr, int sc) {
        memset(dp,-1,sizeof(dp));
        return path(m,n,move,sr,sc);
    }
};