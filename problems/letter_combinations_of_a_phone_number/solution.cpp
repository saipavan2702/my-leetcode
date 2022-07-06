class Solution {
public:
    void track(int x,string&inter,string &d,vector<string>&res)
   {
    string dict[10]={"", "", "abc", "def", "ghi", "jkl", "mno", "qprs", "tuv", "wxyz"};
    if(x==d.size())
    {
        res.push_back(inter);
        return;
    }
    for(auto ch:dict[d[x]-'0'])
    {
        inter[x]=ch;
        track(x+1,inter,d,res);
    }
    }
    vector<string> letterCombinations(string d) {
        if(d.size()==0)
            return {};
         vector<string>res;
    string inter=d;
    track(0,inter,d,res);
    sort(res.begin(),res.end());
    return res;
    }
};