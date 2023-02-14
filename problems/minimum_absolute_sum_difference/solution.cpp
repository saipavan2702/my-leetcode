class Solution {
public:
    int MOD = 1e9+7;
    int minAbsoluteSumDiff(vector<int>& E, vector<int>& F) {
        int n=E.size();

        vector<int>pre(n);
        long long s=0,Q=0;
        for(int i=0;i<n;i++){
            pre[i]=abs(E[i]-F[i]);
            s+=abs(E[i]-F[i])%MOD;
        }
        Q=s;
        sort(E.begin(),E.end());

        for(int i=0;i<n;i++) {

            int d=pre[i];

            int lo=0,hi=n-1;
            int idx=0;

            while(lo<hi) {
                
                int u=lo+(hi-lo)/2;

                if(E[u]>F[i])
                hi=u;
                else
                lo=u+1,idx=lo;

                d=min(d,abs(E[u]-F[i]));
            }

            d=min(d,abs(F[i]-E[idx]));
            Q=min(Q,s-pre[i]+d);
        }
        return Q%MOD;

    }
};