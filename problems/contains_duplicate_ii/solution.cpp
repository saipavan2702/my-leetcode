class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int i=0,n,j;
        set<int>st;
        n=nums.size();
        for(i=0;i<n;i++)
        {
            if(i>k)
            st.erase(nums[i-k-1]);
            if(st.find(nums[i])!=st.end())
                return 1;
            
            st.insert(nums[i]);
        }
       return 0;
    }
};