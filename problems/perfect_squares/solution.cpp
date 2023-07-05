class Solution {
public:
    int numSquares(int n) {
        int k=sqrt(n);

        vector<vector<int>>dp(k+1,vector<int>(n+1,-1));
        function<int(int,int)>recur=[&](int i, int s)->int{
            if(s<0 || i*i>n)return 1e9;
            if(s==0)return 0;
            if(dp[i][s]!=-1)return dp[i][s];

            return dp[i][s]=min(1+recur(i,s-i*i),recur(i+1,s));
        };
        return recur(1,n);
    }
};