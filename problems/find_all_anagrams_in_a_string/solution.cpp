class Solution {
public:
    bool check(int freq[],int count[])
    {
        for(int i=0;i<26;i++)
        if(freq[i]!=count[i])
        return 0;
        
        return 1;
    }
    vector<int> findAnagrams(string s, string p) {
        int n,q;
        n=s.size();
        q=p.size();
        int freq[26]={0};
        int count[26]={0};
        int i=0;
        
        vector<int>ans;
        for(auto&x:p)
        count[x-'a']++;
        
        while(i<n)
        {
          freq[s[i]-'a']++;
          if(i>=q)
          freq[s[i-q]-'a']--;
            
          if(check(freq,count))
          ans.push_back(i-q+1);
            
          i++;
        }
        return ans;
    }
};