class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(begin(nums),end(nums));
        int n=nums.size();
        int a=min(nums[n-1]-nums[0],nums[n-1]-nums[2]);
        int b=min(nums[n-2]-nums[1],nums[n-3]-nums[0]);
        return min(a,b);
    }
};