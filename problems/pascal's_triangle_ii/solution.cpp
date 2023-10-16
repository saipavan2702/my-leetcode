class Solution {
public:
    vector<int> getRow(int I) {
        vector<vector<int>>dp(35,vector<int>(35,0));

        dp[0][0]=1;
        for(int i=1;i<=I;i++){
            for(int j=0;j<=i;j++){
                dp[i][j]=dp[i-1][j]+(j-1>=0?dp[i-1][j-1]:0);
            }
        }

        dp[I].resize(I+1);
        return dp[I];
    }
};