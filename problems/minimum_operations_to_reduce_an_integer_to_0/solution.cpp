class Solution {
public:
    int minOperations(int n) {
        if(n==1)
            return 1;
        if(n==0)
            return 0;
        
        int k=1;
        while(k<n){
            k<<=1;
        }
        int lo=n-k/2;
        int hi=k-n;
        
        if(lo<hi)
        return 1+minOperations(lo);
        else
        return 1+minOperations(hi);
    }
};