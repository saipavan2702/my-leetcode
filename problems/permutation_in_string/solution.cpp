class Solution {
public:
    bool check(int freq[],int count[])
    {
        for(int i=0;i<26;i++)
        if(freq[i]!=count[i])
        return 0;
        
        return 1;
    }
    bool checkInclusion(string s1, string s2) {
        int n,p;
        p=s1.size();
        n=s2.size();
        if(p>n)
        return 0;
        
        int count[26]={0};
        int freq[26]={0};
        
        for(auto&x:s1)
        count[x-'a']++;
        
        for(int i=0;i<n;i++)
        {
            freq[s2[i]-'a']++;
            
            if(i>=p)
            freq[s2[i-p]-'a']--;
            
            if(check(freq,count))
            return 1;
        }
        return 0;
    }
};