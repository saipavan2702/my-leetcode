class Solution {
public:
    int rob(vector<int>& nums) {
        int n;n=nums.size();
        if(n==1)
        return nums[0];
        
        int dp[105];
        int arr[105];
        
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<n-1;i++)
        {
            dp[i]=max(dp[i-2]+nums[i],dp[i-1]);
        }
        arr[1]=nums[1];
        arr[0]=0;
        for(int i=2;i<n;i++)
        {
            arr[i]=max(arr[i-2]+nums[i],arr[i-1]);
        }
        return max(dp[n-2],arr[n-1]);
    
    }
};