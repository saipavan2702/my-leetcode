class Solution {
public:
    int change(int need, vector<int>& coins) {
        int n=coins.size();
        int dp[305][5005];
        memset(dp,0,sizeof(dp));
        for(int i=0;i<=need;i++)dp[0][i]=(i%coins[0])==0;

        for(int i=1;i<n;i++){
            for(int j=0;j<=need;j++){
                if(j>=coins[i])
                dp[i][j]=dp[i-1][j]+dp[i][j-coins[i]];
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[n-1][need];
    }
};