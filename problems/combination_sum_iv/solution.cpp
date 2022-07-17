class Solution {
public:
    int dp[1005];
    int dfs(vector<int>&nums,int target)
    {
        if(target==0)
        return 1;
        if(target<0)
        return 0;
        if(dp[target]!=-1)
        return dp[target];
        int cnt=0;
        for(int i=0;i<nums.size();i++)
        {
            cnt+=dfs(nums,target-nums[i]);
        }
        
        return dp[target]=cnt;
    }
    int combinationSum4(vector<int>& nums, int target) {
        memset(dp,-1,sizeof(dp));
        return dfs(nums,target);
    }
};