class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        int dp[1005];
        memset(dp,-1,sizeof(dp));

        function<int(int)>recur=[&](int i){
            if(i>=n) return 0;
            if(dp[i]!=-1)return dp[i];

            int ans=0;
            ans=cost[i]+recur(i+1);
            ans=min(ans,cost[i]+recur(i+2));

            return dp[i]=ans;
        };
        return min(recur(0),recur(1));
    }
};