class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int t) {
        if(binary_search(nums.begin(), nums.end(), t)==0)
            return {-1, -1};
        int start = lower_bound(nums.begin(), nums.end(), t) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), t) - nums.begin() - 1;
        
        return {start, end};
    }
};