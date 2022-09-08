class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.size()<k)
        return 0;
        int freq[26]={0};
        for(auto&x:s)
        freq[x-'a']++;
        
        int cnt=0;
        for(int i=0;i<26;i++)
        if(freq[i]&1)
        cnt++;
        
        return cnt<=k;
    }
};