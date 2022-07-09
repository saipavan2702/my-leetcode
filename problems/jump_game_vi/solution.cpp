class Solution {
public:
    /*int dict(vector<int>&nums,vector<int>&dp,int k,int x)
    {
         int n;
        n=nums.size();
        if(dp[x]!=INT_MIN)
        {
            return dp[x];
        }
        for(int i=1;i<=k;i++)
        {   
         if(i+x<n)   
         dp[x]=max(dp[x],nums[x]+dict(nums,dp,k,i+x));
        }
        return dp[x];
    }*/
    int maxResult(vector<int>& nums, int k) {
         int n;
        n=nums.size();
        vector<int>dp(n,INT_MIN);
        multiset<int>st;
        dp[0]=nums[0];
        st.insert(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(i>k)
            {st.erase(st.find(dp[i-k-1]));}
            dp[i]=*rbegin(st)+nums[i];
            st.insert(dp[i]);
        }
        return dp[n-1];
        //return dict(nums,dp,k,0);
    }
};