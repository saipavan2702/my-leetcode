class Solution {
public:
    vector<vector<int>> dp;
    int recur(vector<int>& nums, vector<int>& multi, int r,int x, int y)
    {
        int p;
        p=multi.size();
        
        if(r==p)
        return 0;
        
        if(dp[r][x]!=INT_MIN)
        return dp[r][x];
        
        int a=nums[x]*multi[r]+recur(nums,multi,r+1,x+1,y);
        int b=nums[y]*multi[r]+recur(nums,multi,r+1,x,y-1);
        
        return dp[r][x]=max(a,b);
        
    }
    int maximumScore(vector<int>& nums, vector<int>& multi) {
        int n,p;
        n=nums.size();
        p=multi.size();
        
        dp.resize(p+1,vector<int>(p+1,INT_MIN));
        return recur(nums,multi,0,0,n-1);
        
    }
};