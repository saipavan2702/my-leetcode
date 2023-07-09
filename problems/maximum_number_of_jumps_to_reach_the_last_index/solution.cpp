class Solution {
public:
    using ll=long long;
    int maximumJumps(vector<int>& A, int t) {
        ll dp[1005];
        memset(dp,-1,sizeof(dp));
        
        int n=A.size();
        function<ll(int)>recur=[&](int i)->ll{
            if(i>n-1)return 0;
            if(i==n-1)return 1;
            
            if(dp[i]!=-1)return dp[i];
            
            ll ans=0;
            for(int j=i+1; j<n;j++){
                if((ll)-t<=(ll)(A[j]-A[i]) and (ll)t>=(ll)(A[j]-A[i]) and recur(j))
                ans=max(ans,1+recur(j));
            }
            return dp[i]=ans;
        };
        int need=recur(0);
        if(need==0) return -1;
        
        return need-1;
    }
};