class Solution {
public:
    int findLength(vector<int>&a, vector<int>&b) {
        int n,p;
        n=a.size();
        p=b.size();
        
        if(n==0 or p==0)
        return 0;
    
        int res=0;
        vector<vector<int>>dp(n+1,vector<int>(p+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=p;j++)
            {
                if(a[i-1]==b[j-1])
                dp[i][j]=1+dp[i-1][j-1];
                else
                dp[i][j]=0;
                
                res=max(res,dp[i][j]);
            }
        }
        return res;
    }
};