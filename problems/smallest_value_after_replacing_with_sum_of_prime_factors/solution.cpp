class Solution {
public:
    int smallestValue(int n) {
        int l=n;
        while(1)
        {
            int r=l,s=0,c=2;
            while(r>1)
            {
                if(r%c==0)
                s+=c,r/=c;
                else
                c++;
            }
            if(l==s)
            break;
            else
            l=s;
        }
        return l;
    }
};