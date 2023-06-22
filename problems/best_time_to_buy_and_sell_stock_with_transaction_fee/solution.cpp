class Solution {
public:
    int maxProfit(vector<int>& price, int fee) {
        int n=price.size();
        vector<vector<int>>dp(n,vector<int>(2,-1));

        function<int(int,bool)>recur=[&](int i, bool h){
            if(i>=n)
            return 0;

            if(dp[i][h]!=-1)
            return dp[i][h];

            int can=-1e9;
            if(h){
                can=price[i]+recur(i+1,!h)-fee;
                can=max(can,recur(i+1,h));
            }else{
                can=-price[i]+recur(i+1,!h);
                can=max(can,recur(i+1,h));
            }
            return dp[i][h]=can;
        };
        return recur(0,0);
    }
};