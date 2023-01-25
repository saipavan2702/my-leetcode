class Solution {
public:
    bool isReachable(int X, int Y) {
        int n=__gcd(X,Y);
        return (n&(n-1))==0;
    }
};