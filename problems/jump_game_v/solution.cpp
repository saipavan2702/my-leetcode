class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        int dp[1005];
        memset(dp,-1,sizeof(dp));

        function<int(int)>recur=[&](int i){
            if(dp[i]!=-1)return dp[i];

            int u=1;
            for(int j=i-1;j>=max(0,i-d) and arr[i]>arr[j];j--)
            u=max(u,1+recur(j));

            for(int j=i+1;j<=min(i+d,n-1) and arr[i]>arr[j];j++)
            u=max(u,1+recur(j));

            return dp[i]=u;
        };
        
        int ans=1;
        for(int i=0;i<n;i++) ans=max(ans,recur(i));
        return ans;
    }
};