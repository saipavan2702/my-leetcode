class Solution {
public:
    int minDifference(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int res,n;
        res=INT_MAX;
        n=nums.size();
        if(n<=4)
        return 0;
        
        int j=n-4;
        for(int i=0;j<n;i++,j++)
        {
            res=min(res,nums[j]-nums[i]);
        }
        return res;
    }
};