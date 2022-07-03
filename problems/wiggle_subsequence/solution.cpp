class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
    int n = nums.size();
    if (n == 0) return 0;
    int l = 1, r = 1;
    
    for (int i = 1; i < n; ++i) {
        if (nums[i] > nums[i-1]) {
            l = r + 1;
        } else if (nums[i] < nums[i-1]) {
            r = l + 1;
        }
    }
    return max(l, r);
    }
};