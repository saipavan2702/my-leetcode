class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n;
        n=nums.size();
        
        int ans=INT_MIN;
        sort(nums.rbegin(),nums.rend());
        
        unordered_map<int,int>freq;
        for(auto x:nums)
            freq[x]++;
        
        for(int i=0;i<n;i++)
        {
            int len=1;
            int x=nums[i];
            while(freq[sqrt(x)]>0)
            {
                int r=sqrt(x);
                
                if(r*r==x)
                len++;
                else
                break;
                
                freq[sqrt(x)]--;
                x=sqrt(x);
            }
            ans=max(ans,len);
        }
        return ans==1?-1:ans;
    }
};