class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        int n;n=nums.size();
        int l;
        l=i+1;
       while(l<n)
        {
            if(nums[i]!=nums[l])
            {
                i++;
                nums[i]=nums[l];
            }
               l++;
        }
        return ++i;
        
    }
};