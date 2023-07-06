class Solution {
public:
    int numDecodings(string s) {
        int n=s.size();
        int dp[105];
        memset(dp,-1,sizeof(dp));

        function<int(int)>recur=[&](int i){
            if(i>=n)return 1;
            if(s[i]=='0') return 0;
            if(dp[i]!=-1)return dp[i];

            int res=0;
            res+=recur(i+1);
            if(i+1<n and (s[i]=='1' or (s[i]=='2' and s[i+1]<'7')))
            res+=recur(i+2);

            return dp[i]=res;
        };
        return recur(0);
    }
};