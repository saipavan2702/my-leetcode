class Solution {
public:
    int longestArithSeqLength(vector<int>& A) {
        int n=A.size();
        int dp[1005][1005]={0};

        int h=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int diff=A[i]-A[j]+500;
                dp[i][diff]=dp[j][diff]>0?dp[j][diff]+1:2;
                h=max(h,dp[i][diff]);
            }
        }
        return h;
    }
};