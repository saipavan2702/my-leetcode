class Solution {
public:
    const int MOD = 1000000007;
    using vll=vector<long long>;
    int numWays(int steps, int arrLen) {
        
        vector<vll> dp(steps + 1, vll(min(arrLen, steps) + 1, -1));
        return recur(steps, 0, arrLen, dp);
    }
    
    long long recur(int step, int i, int arrLen,vector<vll>& dp) {
        if (step == 0) {
            return (i == 0) ? 1 : 0;
        }
        if (step < 0 || i < 0 || i >= arrLen) {
            return 0;
        }
        if (dp[step][i] != -1) {
            return dp[step][i];
        }
        
        long long ways = recur(step - 1, i, arrLen, dp) % MOD;
        ways += recur(step - 1, i - 1, arrLen,dp) % MOD;
        ways += recur(step - 1, i + 1, arrLen,dp) % MOD;
        
        dp[step][i] = ways % MOD;
        return ways % MOD;
    }
};