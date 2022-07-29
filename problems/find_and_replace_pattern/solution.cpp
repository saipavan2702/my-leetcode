class Solution {
public:
    vector<string> findAndReplacePattern(vector<string>& words, string p) {
        vector<string>res;
       
        for(auto&x:words)
        {
            int i=0;
            bool a=1;
            unordered_map<char,char>freq,data;
            for(auto&y:x)
            {
                if(freq.find(p[i])==freq.end() and data.find(y)==data.end())
                {
                    freq[p[i]]=y;
                    data[y]=p[i];
                }
                else
                {
                    if(freq[p[i]]!=y or data[y]!=p[i])
                    {a=0;}
                }
                i++;
            }
            if(a)
            res.push_back(x);
        }
        return res;
    }
};