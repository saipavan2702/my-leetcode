class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int x=0,y=0,z=0;
        int n,q;n=s1.size();q=s2.size();
        int p;p=s3.size();
        if(n+q!=p)
        return 0;
        vector<vector<bool>>dp(n+1,(vector<bool>(q+1)));
                               
        for(int i=0;i<=n;i++)
        {
          for(int j=0;j<=q;j++)
          {
              if(i==0 and j==0)
                dp[i][j]=1;
              else if(j==0)
               dp[i][j]=(s1[i-1]==s3[i-1] and dp[i-1][j]);
              else if(i==0)
               dp[i][j]=(s2[j-1]==s3[j-1] and dp[i][j-1]);
              else
                dp[i][j]=((s1[i-1]==s3[i+j-1] and dp[i-1][j]) or (s2[j-1]==s3[j+i-1] and dp[i][j-1]));
              
          }
        }
        return dp[n][q];
    }
};