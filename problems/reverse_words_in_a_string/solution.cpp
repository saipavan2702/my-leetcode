class Solution {
public:
    string reverseWords(string s) {
        stringstream str(s);
        string ans="",w;
        while(str>>w)
        ans=w+" "+ans;
        
        ans.pop_back();
        return ans;
    }
};