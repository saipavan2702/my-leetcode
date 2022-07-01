class Solution {
public:
    bool repeatedSubstringPattern(string s) {
    int n;
    n=s.size();
    string a;
    a=(s+s).substr(1,2*n-2);
    return a.find(s)!=-1;
    }
};