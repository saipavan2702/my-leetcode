class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string,int>freq;
        int len=0;
        for(auto&x:words)
        {
            auto str=x;
            reverse(str.begin(),str.end());
            if(freq[str]>0)
            {
              len+=4;
              freq[str]--;
            }
            else
            freq[x]++;
            
        }
        for(auto &x:freq)
        {
            if(x.first[0]==x.first[1] and x.second)
            {len+=2;break;}
        }
        return len;
    }
};