class Solution {
public:
    bool isHappy(int n) {
         if(n==1)
    return 1;
    if(n==7)
    return 1;
    int sus;
    while(n>9)
    {
        sus=0;
        while(n>0)
        {
           int l;
           l=n%10;
           sus+=l*l;
           n/=10;
        }
        if(sus==1)
        return 1;

        n=sus;
    }
    return n==7?1:0;
    }
};