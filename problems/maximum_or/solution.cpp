class Solution {
public:
    long long maximumOr(vector<int>& A, int k) {
        int n=A.size();
        
        long long ans=0;
        vector<long long>pref(n+1),suff(n+1);
        
        pref[0]=0;
        for(int i=1;i<=n;i++){
            pref[i]=pref[i-1]|A[i-1];
        }
        
        suff[n]=0;
        for(int i=n-1;i>=0;i--){
            suff[i]=suff[i+1]|A[i];
        }
        
        for(int i=0;i<n;i++){
            long long need=(long long)A[i]<<k;
            ans=max(ans,(suff[i+1]|need|pref[i]));
        }
        
        return ans;
    }
};