class Solution {
public:
    long long dp[100005];
    long long recur(int i, vector<vector<int>>&Q){
        int n=Q.size();

        if(i>=n)
        return 0;

        if(dp[i]!=-1)
        return dp[i];

        long long take=Q[i][0]+recur(i+Q[i][1]+1, Q);
        long long leave=recur(i+1,Q);

        return dp[i]=max(take,leave);
    }
    long long mostPoints(vector<vector<int>>& Q) {
        int n=Q.size();
        memset(dp,-1,sizeof(dp));
        return recur(0,Q);
    }
};