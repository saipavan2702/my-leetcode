class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n,res=INT_MIN;
        n=nums.size();
        int dp[1001][1001]={0};
    
        for(int i=0;i<n;i++)
        {
          for(int j=0;j<i;j++)
          {
              int diff=nums[i]-nums[j]+500;
              dp[i][diff]=dp[j][diff]>0?dp[j][diff]+1:2;
              res=max(res,dp[i][diff]);
          }
        }
        return res;
        
    }
};