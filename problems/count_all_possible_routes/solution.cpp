class Solution {
public:
    const int MOD=1e9+7;
    int countRoutes(vector<int>& loc, int S, int F, int fuel) {
        int n=loc.size();
        int cn=0;
        int dp[105][205];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int i, int use)->int{
            if(use>fuel)
            return 0;

            if(dp[i][use]!=-1)
            return dp[i][use];
            
            int ans=i==F?1:0;
            for(int j=0;j<n;j++){
                if(j==i)
                continue;

                ans=(ans%MOD+recur(j,use+abs(loc[i]-loc[j]))%MOD)%MOD;
            }
            return dp[i][use]=ans%MOD;
        };

        cn=recur(S,0);
        return cn%MOD;
    }
};