class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int n=size(A);

        // int curr(0),global(-1e9);
        // for(int i=0;i<n;i++){
        //     curr+=A[i];
        //     curr=max(A[i],curr);
        //     global=max(global,curr);
        // }
        // return global;

        vector<int>dp(n);
        for(int i=0;i<n;i++)dp[i]=A[i];
        for(int i=1;i<n;i++){
            dp[i]=max(dp[i],A[i]+dp[i-1]);
        }
        return *max_element(dp.begin(),dp.end());
    }
};