class Solution {
public:
    int commonFactors(int a, int b) {
        int r=0;
        int n=__gcd(a,b);
        
        for(int i=1;i*i<=n;i++)
        {
            if(n%i==0)
            {
                if(n/i==i)
                r++;
                else
                r+=2;
            }
        }
        return r;
    }
};