class Solution {
public:
    int concatenatedBinary(int n) {
        long ans=0,mod=1e9+7;
        for(int i=1;i<=n;i++)
        {
            int r=log2(i)+1;
            ans=((ans<<r)%mod+i)%mod;
        }
        return ans;
    }
};