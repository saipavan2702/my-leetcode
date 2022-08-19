class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n;
        n=nums.size();
        unordered_map<int,int>freq,dict;
        for(int x:nums)
        freq[x]++;
        
        for(int i:nums)
        {
            if(freq[i]==0)
            continue;
            
            freq[i]--;
            if(dict[i-1]>0)
            {
             dict[i-1]--;
             dict[i]++;
            }
            else if(freq[i+2]>0 and freq[i+1]>0)
            {
                freq[i+1]--;
                freq[i+2]--;
                dict[i+2]++;
            }
            else
            return 0;
        }
        return 1;
    }
};