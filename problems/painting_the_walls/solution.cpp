class Solution {
public:
    using vi=vector<int>;
    int dp[505][505];
    int solve(vi &cost, vi &time, int i, int bank){
        if(bank <= 0){
            return 0;
        }
        if(i >= cost.size()){
            return 1e9;   
        }
        if(dp[i][bank] != -1){
            return dp[i][bank];
        }
        else {
            int notTake = solve(cost, time, i+1, bank);
            int take=cost[i]+solve(cost, time, i+1, bank -  time[i] -1); 
            return dp[i][bank] = min(notTake, take);      
        }
    }

    int paintWalls(vector<int>& cost, vector<int>& time) {
        memset(dp,-1,sizeof(dp));
        return solve(cost, time, 0, time.size());
    }
};