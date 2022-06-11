class Solution {
public:
    bool strongPasswordCheckerII(string s) {
        set<char>st;
        int i,n;
        int l=0,k=0,m=0,j=0;
        if(s.size()<8)
        {
            return false;
        }
        for(i=0;i<s.size();i++)
        {
            if(s[i]==s[i+1])
            {
                return false;
            }
        }
        for(auto i:s)
        {
            st.insert(i);
        }
        for(auto i:st)
        {
            if(i>='0' and i<='9')
            {
                l=1;
            }
            else if(i>='a' and i<='z')
            {
                k=1;
            }
            else if(i>='A' and i<='Z')
            {
                m=1;
            }
            else if(i=='!' or i=='@' or i=='#' or i=='$' or i=='%' or i=='^' or i=='&' or i=='*' or i=='(' or i==')' or i=='-' or i=='+')
            {
                j=1;
            }    
        }
        return l&&k&&m&&j;
    }
};