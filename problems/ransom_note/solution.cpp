class Solution {
public:
    bool canConstruct(string r, string g) {
      int n,p;
      n=r.size();
      p=g.size();
      
      int freq[26]={0};
      for(int i=0;i<p;i++)
      freq[g[i]-'a']++;
        
      for(int i=0;i<n;i++)
      {
          int a=freq[r[i]-'a']--;
          if(a<=0)
          return 0;
      }
      return 1;
    }
};