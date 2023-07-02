class Solution {
public:
    int jump(vector<int>& A) {
        int n=size(A);
        int dp[10005];
        memset(dp,-1,sizeof(dp));

        function<int(int)>recur=[&](int i)->int{
            if(i>=n-1)return 0;
            if(dp[i]!=-1)return dp[i];

            int ans=1e9;
            for(int k=i+1;k<=A[i]+i;k++){
                ans=min(ans,1+recur(k));
            }
            return dp[i]=ans;
        };
        return recur(0);
    }
};