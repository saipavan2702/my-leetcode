class Solution {
public:
    int addDigits(int n) {
        long long s=0;
        while(n>9){
            while(n){
                s+=n%10;
                n/=10;
            }
            n=s;
            s=0;
        }
        return n;
    }
};