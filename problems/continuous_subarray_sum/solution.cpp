class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n;
        n=nums.size();
        
        int curr=0;
        unordered_map<int,int>freq;
        freq[0]=-1;
        for(int i=0;i<n;i++)
        {
            curr+=nums[i];
            curr%=k;
            if(freq.find(curr)!=freq.end())
            {
                if(i-freq[curr]>1)
                  return 1;
            }
            else
            freq[curr]=i;
        }
        return 0;
    }
};