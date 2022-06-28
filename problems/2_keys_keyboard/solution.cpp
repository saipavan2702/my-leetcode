class Solution {
public:
    int minSteps(int n) {
        int re=0;
        for(int i=2;i<=n;i++)
        {
            while(n%i==0)
            {re+=i;
            n/=i;}
        }
        return re;
    }
};