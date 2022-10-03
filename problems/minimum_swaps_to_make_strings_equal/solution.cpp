class Solution {
public:
    int minimumSwap(string s1, string s2) {
        int r=0,l=0;
        int n;
        n=s1.size();
        for(int i=0;i<n;i++)
        {
            if(s1[i]=='x' and s2[i]=='y')
            r++;
            else if(s1[i]=='y' and s2[i]=='x')
            l++;
        }
        if(r%2!=l%2)
        return -1;
        
        return r/2+l/2+(r%2)*2;
    }
};