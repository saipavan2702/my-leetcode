class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        vector<int>p;
        int i=0,j=n;
        while(i<n && j<2*n){
            p.push_back(nums[i++]);
            p.push_back(nums[j++]);
        }
        return p;
    }
};