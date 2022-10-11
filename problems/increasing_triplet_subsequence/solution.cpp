class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int a=INT_MAX;
        int b=INT_MAX;
        int n;
        n=nums.size();
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]<a)
                a=nums[i];
            else if(nums[i]>a && nums[i]<b)
                b=nums[i];
            else if(nums[i]>b)
                return 1;
        }
        return 0;
        
    }
};