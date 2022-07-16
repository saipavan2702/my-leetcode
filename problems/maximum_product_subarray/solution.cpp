class Solution {
public:
    int maxProduct(vector<int>& nums) {
         int max_so_far = nums[0], min_so_far = nums[0], res = nums[0];
        int n = nums.size();
        
        for(int i=1;i<n;i++){
            if(nums[i]<0) swap(max_so_far, min_so_far);
            max_so_far = max(nums[i], nums[i]*max_so_far);
            min_so_far = min(nums[i], nums[i]*min_so_far);
            
            res= max(res, max_so_far);
        }
        return res;
    }
};