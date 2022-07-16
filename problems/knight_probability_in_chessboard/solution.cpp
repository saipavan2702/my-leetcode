class Solution {
public:
    double track(int n,int k,int sr,int sc,vector<vector<vector<double>>> & dp)
    {
        if(sr<0 or sr>=n or sc<0 or sc>=n)
        return 0.0;
        
        if(k==0)
        return 1.0;
        
        if(dp[sr][sc][k]!=-1)
        return dp[sr][sc][k];
        
        double a=track(n,k-1,sr-2,sc+1,dp);
        double b=track(n,k-1,sr+2,sc+1,dp);
        double c=track(n,k-1,sr+2,sc-1,dp);
        double d=track(n,k-1,sr-2,sc-1,dp);
        double e=track(n,k-1,sr-1,sc+2,dp);
        double f=track(n,k-1,sr+1,sc+2,dp);
        double g=track(n,k-1,sr-1,sc-2,dp);
        double h=track(n,k-1,sr+1,sc-2,dp);
        
        dp[sr][sc][k]= 0.125*(a+b+c+d+e+f+g+h);
        
        return dp[sr][sc][k];
        
    }
    double knightProbability(int n, int k, int sr, int sc) {
        vector<vector<vector<double>>> dp(n + 1, vector<vector<double>> (n+ 1, vector<double>(k + 1, -1)));
        return track(n,k,sr,sc,dp);
    }
};