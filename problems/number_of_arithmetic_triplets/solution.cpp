class Solution {
public:
    int arithmeticTriplets(vector<int>& nums, int diff) {
        int cnt=0;
       unordered_map<int,bool>freq;
       for(int i:nums)
          freq[i]=1;
        
        for(int i:nums)
        {
            if(freq[i-diff] and freq[i+diff])
                cnt++;
            
        }
        return cnt;
    }
};