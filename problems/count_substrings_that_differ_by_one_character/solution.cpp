class Solution {
public:
    int countSubstrings(string s, string t) {
         int n,p;
    n=s.size();
    p=t.size();
    int dp[101][101]={0};
    int freq[101][101]={0};
    int cnt=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=p;j++)
        {
          if(s[i-1]==t[j-1])
          {
            dp[i][j]=1+dp[i-1][j-1];
            freq[i][j]=freq[i-1][j-1];
          }
          else
          {
            freq[i][j]=1+dp[i-1][j-1];
          }
          cnt+=freq[i][j];
        }
    }
    return cnt;
    }
};