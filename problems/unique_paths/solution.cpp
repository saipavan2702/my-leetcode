class Solution {
public:
    int uniquePaths(int m, int n) {
     vector<vector<int>>dp(m,vector<int>(n,-1));

     function<int(int,int)>dfs=[&](int x, int y){
        if(x<0 || x>=m || y<0 || y>=n)
        return 0;

        if(x==m-1 and y==n-1)
        return 1;

        if(dp[x][y]!=-1)
        return dp[x][y];

        int op1=dfs(x+1,y);
        int op2=dfs(x,y+1);

        return dp[x][y]=op1+op2;
     };

     return dfs(0,0);
    }
};