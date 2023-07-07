class Solution {
public:
    bool canReach(string s, int sJ, int hJ) {
        int n=s.size();
        vector<bool>dp(n,false);
        if(s[n-1]=='1') return 0;

        dp[0]=true;
        int st=0,en=0;
        for(int u=0;u<n;u++) {
            if(!dp[u]) continue;

            st=max(u+sJ,en+1);
            en=min(u+hJ,n-1);
            
            for(int i=st;i<=en;i++)
            if(s[i]=='0') dp[i]=true;

            if(dp[n-1]) return 1;
        }
        return dp[n-1];
    }
};