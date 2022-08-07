 #define mod 1000000007
class Solution {
public:
    int recur(int pre,int cnt,int&n,vector<vector<int>>&dp)
    {
        if(cnt==n)
        return 1;
        
        if(dp[cnt][pre]!=-1)
        return dp[cnt][pre]%mod;
        
        int x=0;
        for(int i=1;i<=5;i++)
        {
            if(pre==1 and i==2)
              x=(x%mod+recur(i,cnt+1,n,dp)%mod)%mod;
            else if(pre==2 && (i==1 || i==3))
              x=(x%mod+recur(i,cnt+1,n,dp)%mod)%mod;
            else if(pre==3 and i!=3)
              x=(x%mod+recur(i,cnt+1,n,dp)%mod)%mod;
            else if(pre==4 and (i==3 or i==5))
              x=(x%mod+recur(i,cnt+1,n,dp)%mod)%mod;
            else if(pre==5 and i==1)
              x=(x%mod+recur(i,cnt+1,n,dp)%mod)%mod;
        }
        return dp[cnt][pre]=x%mod;
    }
    int countVowelPermutation(int n) {
        vector<vector<int>>dp(n+1,vector<int>(6,-1));
        int x=0;
        for(int i=1;i<=5;i++)
        {
            x=(x%mod+recur(i,1,n,dp)%mod)%mod;
        }
        return x%mod;
    }
};