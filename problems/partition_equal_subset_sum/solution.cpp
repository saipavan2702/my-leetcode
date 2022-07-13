class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n;n=nums.size();
    int sum=0;
    sum=accumulate(nums.begin(),nums.end(),sum);
    if(sum&1)
    return 0;
    cout<<sum;
    sum/=2;
  
   bool dp[n+1][sum+1];  
    for(int i=0;i<=n;i++)
    dp[i][0]=1;
    for(int i=1;i<=sum;i++)
    dp[0][i]=0;

    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=sum;j++)
        {
           if(nums[i-1]<=j)
           dp[i][j]=(dp[i-1][j-nums[i-1]] or dp[i-1][j]);
           else
           dp[i][j]=dp[i-1][j];
            
        }
    }
    return dp[n][sum];
    }
};