class Solution {
public:
    int candy(vector<int>& r) {
        int n,l=1;n=r.size();
       vector<int>dp(n,1);
        dp[0]=1;int ans=0;
        for(int i=1;i<n;i++)
        {
            if(r[i]>r[i-1])
            {
                dp[i]=dp[i-1]+1;
            }
        }
        for(int i=n-2;i>=0;i--)
        {
            if(r[i]>r[i+1])
            {
                dp[i]=max(dp[i],1+dp[i+1]);
            }
        }
        for(auto x:dp)
        {
            ans+=x;
        }
        return ans;
    }
};