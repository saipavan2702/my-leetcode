class Solution {
public:
    int maxProfit(vector<int>& p) {
        int n=size(p);

        vector<vector<vector<int>>>dp(2,vector<vector<int>>(n,vector<int>(2,-1)));

        function<int(int,int,int)> recur=[&](int r,int i,int k){
            if(i>=n || k>=2)
            return 0;

            if(dp[r][i][k]!=-1)
            return dp[r][i][k];

            int send;
            if(!r){
                send=max(recur(r,i+1,k),-p[i]+recur(!r,i+1,k));
            }
            else{
                send=max(recur(r,i+1,k),p[i]+recur(!r,i+1,k+1));
            }
            return dp[r][i][k]=send;

        };
        return recur(0,0,0);
    }
};