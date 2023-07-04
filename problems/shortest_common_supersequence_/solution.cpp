class Solution {
public:
    string shortestCommonSupersequence(string s, string t) {
        int n=s.size();
        int p=t.size();
        vector<vector<string>>dp(n+1,vector<string>(p+1,""));
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(s[i]==t[j])
                dp[i+1][j+1]=dp[i][j]+s[i];
                else
                dp[i+1][j+1]=dp[i+1][j].size()>dp[i][j+1].size()?dp[i+1][j]:dp[i][j+1];
            }
        }

        auto lcs=dp[n][p];
        int i=0,j=0;
        string scs="";
        for(auto &x:lcs){
            while(s[i]!=x)
            scs+=s[i++];

            while(t[j]!=x)
            scs+=t[j++];

            scs+=x;
            i++;j++;
        }
        return scs+s.substr(i)+t.substr(j);
    }
};