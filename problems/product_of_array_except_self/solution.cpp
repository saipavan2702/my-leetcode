class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
         int n=nums.size();
        vector<int>ans(n,1);            
	   int prefix = 1, suffix = 1;     
	   for(int i=0; i<n; i++)
	   {     
	     ans[i] *= prefix;
     ans[n-i-1] *= suffix;
     prefix *= nums[i];
     suffix *= nums[n-i-1];
   }
   return ans;

    }
};