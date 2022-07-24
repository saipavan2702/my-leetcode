class Solution {
public:
    char repeatedCharacter(string s) {
        char ch;
        int res=INT_MAX;
        unordered_map<char,vector<int>>freq;
        for(int i=0;i<s.size();i++)
        {
            freq[s[i]].push_back(i);
        }
        for(char x:s)
        {
            if(freq.find(x)!=freq.end())
            {
                //for(int i=1;i<freq[x].size();i++)
                    if(freq[x].size()>1)
                    {
                        if(res>freq[x][1])
                       {
                        ch=x;
                        res=freq[x][1];
                       }
                    }
            }
        }
        return ch;
        
    }
};