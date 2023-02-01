class Solution {
public:
    string gcdOfStrings(string s1, string s2) {
        int x=s1.size(),y=s2.size();
        int len=__gcd(x,y);

        if(s1+s2==s2+s1)
        return s2.substr(0,len);

        return "";
    }
};