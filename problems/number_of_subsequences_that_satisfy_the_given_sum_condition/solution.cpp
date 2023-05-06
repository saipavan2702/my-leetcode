class Solution {
public:
    int numSubseq(vector<int>& A, int T) {
        int n=A.size();
        sort(A.begin(),A.end());

        auto test=[&](int f){
            int lo(0),hi(n-1);

            while(lo<=hi){
                int u=(lo+hi)/2;
                if(A[u]<=f)
                lo=u+1;
                else
                hi=u-1;
            }
            return hi;
        };

        int ans=0;
        int mod=(int)1e9+7;

        auto pow2=[&](long long a, long long n){
            long long res=1;
            
            while(n) {
                if(n&1){
                    res=(res*a)%mod;
                    n--;
                }
                else{
                    a=(a*a)%mod;
                    n=n/2;
                }
            }
            return res;
        };

        for(int i=0;i<n;i++){
            int j=test(T-A[i]);
            if(j>=i)
            ans=(ans+(int)pow2(2,j-i))%mod;
        }
        return ans;

      
    }
};