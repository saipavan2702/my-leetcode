class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n=rods.size();
        int dp[21][10005];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int i, int d)->int{
            if(i>=n){
                return d==0?0:-5000;
            }
            if(dp[i][d+5000]!=-1)
            return dp[i][d+5000];

            int r=recur(i+1,d);
            int o=rods[i]+recur(i+1,d+rods[i]);
            int y=recur(i+1,d-rods[i]);

            return dp[i][d+5000]=max({r,o,y});
        };
        int ans=recur(0,0);
        return ans<0?0:ans;
    }
};