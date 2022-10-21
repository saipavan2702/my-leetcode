class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        int n;
        n=nums.size();
       unordered_map<int,int>freq;
        for(int i=0;i<n;i++)
        {
            if(freq.count(nums[i]))
            {
                if(abs(i-freq[nums[i]])<=k)
                return 1;
            }
            freq[nums[i]]=i;
        }
        return 0;
    }
};