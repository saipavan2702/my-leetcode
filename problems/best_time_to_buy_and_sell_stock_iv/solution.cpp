class Solution {
public:
    int dp[1000][2][102];
    int recur(int k,vector<int>&prices,int x,bool r)
    {
        int n;
        n=prices.size();
        
        if(k==0 or x==n)
        return 0;
        
        if(dp[x][r][k]!=-1)
            return dp[x][r][k];
        
        if(!r)
        {
            int a=recur(k,prices,x+1,1)-prices[x];
            int b=recur(k,prices,x+1,0);
            
            return dp[x][r][k]=max(a,b);
        }
        else
        {
            int c=prices[x]+recur(k-1,prices,x+1,0);
            int d=recur(k,prices,x+1,1);
            
            return dp[x][r][k]=max(c,d);
        }
        
    }
    int maxProfit(int k, vector<int>& prices) {
        if(k==0)
        return 0;
        
        memset(dp,-1,sizeof(dp));
        return recur(k,prices,0,0);
    }
};