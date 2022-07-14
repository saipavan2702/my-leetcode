class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& word) {
        vector<string>res;
    
        unordered_set<string>dict;
        for(auto x:word)
        dict.insert(x);
        
        string curr;
      function<void(int)>solve=[&](int i)
      {
        if(i==s.size())
        {
         res.push_back(curr);
         return;
        }
        string str;
        for(int j=i;j<s.size();j++)
        {
            str=s.substr(i,j-i+1);
        if(dict.find(str)!=dict.end())
        {
          if(!curr.empty())
          str=" "+str;
            
          curr+=str;
          solve(j+1);
          curr.erase(curr.size()-str.size());
        }
        }
        
      };
        solve(0);
        return res;
                    
    }
};