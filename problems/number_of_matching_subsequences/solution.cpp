class Solution {
public:
    bool check(string &s,string&t)
    {
        int i=0,j=0,res=0;
        int n,p;n=s.size();p=t.size();
        while(i<n and j<p)
        {
            if(s[i]==t[j])
            i++,j++,res++;
            else
            i++;
        }
        return (res==p);
    }
    int numMatchingSubseq(string s, vector<string>&dict) {
        int n,cnt=0;n=s.size();
        unordered_map<string,int>freq;
        for(auto x:dict)
        freq[x]++;
        for(auto x:freq)
        {
            string str=x.first;
            if(check(s,str))
            cnt+=x.second;
        }
        return cnt;
    }
};