class Solution {
public:
    string breakPalindrome(string p) {
        int n;
        n=p.size();
        
        for(int i=0;i<n/2;i++)
        {
            if(p[i]!='a')
            {
             p[i]='a';
             return p;
            }
        }
        p[n-1]='b';
        return n<2?"":p;
    }
};