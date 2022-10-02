class Solution {
public:
    int dp[35][1005];
    long long mod=1e9+7;
    int recur(int n,int k,int t)
    {
        if(t==0 and n==0)
        return 1;
        
        if(n<0)
        return 0;
        
        if(dp[n][t]!=-1)
        return dp[n][t];
        
        long long int cnt=0;
        for(int i=1;i<=k;i++)
        {
            if(t>=i)
            cnt=(cnt+recur(n-1,k,t-i))%mod;
        }
        return dp[n][t]=cnt%mod;
        
    }
    int numRollsToTarget(int n, int k, int target) {
       
        memset(dp,-1,sizeof(dp));
        return recur(n,k,target)%mod;
       
    }
};