class Solution {
public:
    int coinChange(vector<int>& coins, int need) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(need+1,-1));

        function<int(int,int)>recur=[&](int i, int curr){
            if(i>=n || curr<0)
            return INT_MAX-1;

            if(dp[i][curr]!=-1)
            return dp[i][curr];

            if(curr==0)return 0;

            int an=INT_MAX;
            an=1+recur(i,curr-coins[i]);
            an=min(an,recur(i+1,curr));

            return dp[i][curr]=an;
        };
        int an=recur(0,need);
        return an==INT_MAX-1?-1:an;

    }
};