class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int>st;
        int n;
        n=nums.size();
        int curr=0;
        int cnt=0;
        for(int i=0;i<n-1;i++)
        {
           if(st.find(nums[i]+nums[i+1])!=st.end())
           {
               return 1;
           }
           st.insert(nums[i]+nums[i+1]);
        }
        return 0;
        
    }
};