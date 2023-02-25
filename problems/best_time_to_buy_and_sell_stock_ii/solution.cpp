class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=size(p);

        vector<vector<int>>dp(2,vector<int>(n,-1));

        function<int(int,int)> recur=[&](int r,int i){
            if(i>=n)
            return 0;

            if(dp[r][i]!=-1)
            return dp[r][i];

            int send;
            if(!r){
                send=max(recur(r,i+1),-p[i]+recur(!r,i+1));
            }
            else{
                send=max(recur(r,i+1),p[i]+recur(!r,i+1));
            }
            return dp[r][i]=send;

        };
        return recur(0,0);
    }
};