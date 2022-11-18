class Solution {
public:
    bool isUgly(int n) {
        if(n<1)
        return 0;
        
        while(n%2==0 and n!=1)
        n/=2;
        
        while(n%3==0 and n!=1)
        n/=3;
        
        while(n%5==0 and n!=1)
        n/=5;
        
        return n==1;
    }
};