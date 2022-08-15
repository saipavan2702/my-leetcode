class Solution {
public:
    int romanToInt(string s) {
        char r[7]={'M','D','C','L','X','V','I'};
        int t[]={1000,500,100,50,10,5,1};
        unordered_map<char,int>freq;
        for(int i=0;i<7;i++)
        {
            freq[r[i]]=t[i];
        }
        int cnt=0;
        int n;
        n=s.size();
        cnt=freq[s[n-1]];
        for(int i=0;i<n-1;i++)
        {
            if(freq[s[i]]<freq[s[i+1]])
            cnt-=freq[s[i]];
            else
            cnt+=freq[s[i]];
        }
        return cnt;
    }
};