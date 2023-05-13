class Solution {
public:
    int countGoodStrings(int lo, int hi, int z, int one) {
        long long MOD=1e9+7;

        int dp[100005];
        memset(dp,-1,sizeof(dp));

        function<int(int)>recur=[&](int len){
            if(len>hi)
            return 0;

            if(dp[len]!=-1)
            return dp[len];

            int ans=0;
            if(len>=lo && len<=hi)
            ans=1;
            
            ans+=(recur(len+z)%MOD);
            ans=(ans%MOD+recur(len+one)%MOD)%MOD;

            return dp[len]=ans;
        };
        return recur(0) ;
    }
};