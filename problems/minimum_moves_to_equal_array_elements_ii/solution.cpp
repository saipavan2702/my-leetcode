class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int res=0,n;
        n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n/2;i++)
        {
            res+=nums[n-i-1]-nums[i];
        }
        return res;
    }
};