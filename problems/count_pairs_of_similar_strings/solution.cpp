class Solution {
public:
    int similarPairs(vector<string>& w) {
        map<string,int>dict;
        for(auto&x:w)
        {
            set<char>ret;
            for(auto&y:x)
            ret.insert(y);
            
            string s="";
            for(auto t:ret)
                s+=t;
            
            dict[s]++;
        }
        int cnt=0;
        for(auto x:dict)
        {
            int y=x.second;
            if(y>1)
            cnt=cnt+(y*(y-1))/2;
        }
        return cnt;
    }
};