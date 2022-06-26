#define MOD 1000000007
class Solution {
public:
    long long int fib(int k)
    {
       vector<long long int>dp(k+1,0);
        dp[1]=1;
        for(long long int i=2;i<=k;i++)
        {
         dp[i]=(dp[i-1]+dp[i-2])%MOD;   
        }
        return dp[k];
    }
    int countHousePlacements(int n) {
        long long int res;
        res=fib(n+2);
        return ((res)%MOD*(res)%MOD)%MOD;
    }
};