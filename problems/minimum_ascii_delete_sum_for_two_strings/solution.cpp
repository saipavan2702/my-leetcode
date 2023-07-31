class Solution {
public:
    int minimumDeleteSum(string s, string t) {
        int n=s.size(),p=t.size();

        vector<vector<int>>dp(n+1,vector<int>(p+1,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(s[i]==t[j]) dp[i+1][j+1]=dp[i][j]+s[i];
                else dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]);
            }
        }
        int lcs=dp[n][p];

        int sasc=0,tasc=0;
        for(int i=0;i<n;i++) sasc+=s[i];
        for(int i=0;i<p;i++) tasc+=t[i];

        return abs(lcs-tasc)+abs(lcs-sasc);
    }
};