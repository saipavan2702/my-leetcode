class Solution {
public:
    bool isMatch(string s, string p) {
        int n=s.size();
        int q=p.size();

        vector<vector<int>>dp(n+1,vector<int>(q+1,-1));
        function<bool(int,int)>recur=[&](int i, int j)->bool{
           if(i>=n and j>=q)
           return 1;
           if(j>=q)return 0;

           if(dp[i][j]!=-1)
           return dp[i][j];
           
           bool isSet=(i<n) and (s[i]==p[j] || p[j]=='.');
           if(j+1<q and p[j+1]=='*')
           return dp[i][j]=recur(i,j+2) or (isSet and recur(i+1,j));

           if(isSet)
           return dp[i][j]=recur(i+1,j+1);

           return dp[i][j]=0;
        };
        return recur(0,0);
    }
};