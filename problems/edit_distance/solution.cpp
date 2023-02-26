class Solution {
public:
    int minDistance(string S, string T) {
        int n=size(S);
        int p=size(T);

        int dp[505][505];
        memset(dp,-1,sizeof(dp));

        for(int i=0;i<=n;i++)
        dp[i][0]=i;

        for(int i=0;i<=p;i++)
        dp[0][i]=i;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=p;j++) {
                
                if(S[i-1]!=T[j-1])
                dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                else
                dp[i][j]=dp[i-1][j-1];

            }
        }
        return dp[n][p];
    }
};