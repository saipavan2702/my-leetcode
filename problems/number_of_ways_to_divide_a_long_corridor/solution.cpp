/**
 * 
 * k = current number of seats
 * i = current position
 * Time complexity = O(N)
 * 
**/
class Solution {
public:
    const int MOD = 1e9 + 7;
    long long dp[100001][3];

    long long getAns(string & a, int i, int k) {
        if(i >= a.size()) {
            return k == 2;
        }
        
        if(dp[i][k] != -1)return dp[i][k];
        
        if(k == 2) {
            if(a[i] == 'P') {
                long long op1= getAns(a, i + 1, 0) % MOD;
                long long op2= getAns(a, i + 1, k) % MOD;
                return dp[i][k]=(op1+op2)%MOD;
            }
            else {
                return dp[i][k] = getAns(a, i + 1, 1) % MOD;
            }
        }
        else {
            return dp[i][k] = getAns(a, i + 1, k + (a[i] == 'S')) % MOD;
        }
        
    }
    int numberOfWays(string corridor) {
        memset(dp, -1, sizeof(dp));
        return getAns(corridor, 0, 0); 
    }
};