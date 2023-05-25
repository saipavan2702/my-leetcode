class Solution {
public:
    double new21Game(int n, int k, int P) {
        if (k==0 || n>=k+P) {
            return 1.0;
        }
        
        double curr=1.0;
        double prob=0.0;
        
        vector<double> dp(n + 1, 0.0);
        dp[0] = 1.0;
        
        for (int i = 1; i <= n; i++) {
            dp[i] = curr/P;
            
            if (i < k) {
                curr+=dp[i];
            } else {
                prob+=dp[i];
            }
            
            if (i>=P) {
                curr-=dp[i-P];
            }
        }
        
        return prob;
    }
};