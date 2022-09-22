class Solution {
public:
    string reverseWords(string s) {
        int n;
        n=s.size();
        
        string ans="";
        stringstream str(s);
        string r;
        while(str>>r)
        {
            reverse(r.begin(),r.end());
            ans+=r;
            ans+=" ";
        }
        string res=ans.substr(0,n);
        return res;
    }
};