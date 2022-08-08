class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==0)
        return 0;
        int dp[2505]={0};
        dp[0]=1;
        for(int i=1;i<nums.size();i++)
        {
            dp[i]=1;
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                dp[i]=max(dp[i],1+dp[j]);    
            }
        }
        return *max_element(dp,dp+2505);
    }
};