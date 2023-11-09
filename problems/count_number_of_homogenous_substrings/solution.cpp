class Solution {
public:
    const int MOD=1e9+7;
    int countHomogenous(string s) {
        int N=s.size();
        int j=0;

        long long n,ans=0;
        for(int i=0;i<N;i++){
            if(s[i]!=s[j]){
                n=i-j+1;
                ans=(ans%MOD+((n*(n-1))/2))%MOD;
                ans%=MOD;
                j=i;
            }
        }
        n=N-j+1;
        ans=(ans%MOD+((n*(n-1))/2))%MOD;
        ans%=MOD;
        return (int)ans;
    }
};