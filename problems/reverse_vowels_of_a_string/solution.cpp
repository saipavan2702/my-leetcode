class Solution {
public:
    bool is(char x)
    {
        return x=='a' or x=='e' or x=='i' or x=='o' or x=='u' or x=='A' or x=='E' or x=='I'
            or x=='O' or x=='U';
    }
    string reverseVowels(string s) {
        string a="";
        for(auto&x:s)
        {
            if(is(x))
            a+=x;
        }
        for(int i=0;i<s.size();i++)
        {
            if(is(s[i]))
            {
                s[i]=a.back();
                a.pop_back();
            }
        }
        return s;
    }
};