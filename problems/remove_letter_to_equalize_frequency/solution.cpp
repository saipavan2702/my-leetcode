class Solution {
public:
    bool equalFrequency(string word) {
        
        int dict[26]={0};
        for(auto&x:word)
        dict[x-'a']++;
        
        
        for(int i=0;i<26;i++)
        {
          if(dict[i]==0)
             continue;
          
          dict[i]--;
          bool l=0,r=0;
          int cnt=0;
          for(int i=0;i<26;i++)
          {
              if(dict[i]==0)
                 continue;
              
              if(!l)
              {
                l=1;
                cnt=dict[i];
              }
              
              if(dict[i]!=cnt)
              {
                  r=1;
                  break;
              }
          }
          if(!r)
          return 1;
            
          dict[i]++;
        }
        return 0;
    }
};