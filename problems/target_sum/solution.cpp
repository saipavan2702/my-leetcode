class Solution {
public:
    int findTargetSumWays(vector<int>& A, int target) {
        int n=size(A);
        
        vector<unordered_map<int,int>>dp(n+1);
        function<int(int,int)>recur=[&](int i, int curr)->int{
            if(i==n) return curr==target;

            if(dp[i].find(curr)!=dp[i].end())
            return dp[i][curr];

            return dp[i][curr]=recur(i+1,curr-A[i])+recur(i+1,curr+A[i]);
        };
        return recur(0,0);
        
    }
};