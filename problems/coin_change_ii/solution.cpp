class Solution {
public:
    int change(int need, vector<int>& coins) {
        int n=coins.size();
        int dp[305][5005];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int i,int curr){
            if(curr==need)return 1;
            if(i>=n || curr>need)return 0;
            if(dp[i][curr]!=-1)return dp[i][curr];

            int ans=recur(i+1,curr)+recur(i,curr+coins[i]);
            return dp[i][curr]=ans;
        };
        return recur(0,0);
    }
};