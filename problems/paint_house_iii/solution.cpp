class Solution {
    #define ll long long int
     ll dp[105][25][105];
 ll helper(vector<int>& houses, vector<vector<int>>& cost,ll m, ll n, ll t,ll i,ll prev)
  {
    if(t<0)
     return INT_MAX;
    if(i==m and t==0)
      return 0;
    if(i==m and t!=0)
        return INT_MAX;
    if(dp[i][prev][t]!=-1)
        return dp[i][prev][t];
    if(houses[i]!=0)
    {
        return dp[i][prev][t]=helper(houses,cost,m,n,t-(prev!=houses[i]),i+1,houses[i]);
    }
    ll ans=INT_MAX;
    for(int j=1;j<=n;j++)
    {
        ans=min(cost[i][j-1]+helper(houses,cost,m,n,t-(prev!=j),i+1,j),ans);
    }
    return dp[i][prev][t]=ans;    
        
    }
public:
    
   
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int t) {
         memset(dp,-1,sizeof(dp));
        ll res=helper(houses,cost,m,n,t,0,n+1);
        if(res==INT_MAX)
         return -1;
        
        return res;
    }
};