class Solution {
public:
    bool canPartition(vector<int>& A) {
        int n=A.size();
        int tot=accumulate(begin(A),end(A),0);
        if(tot&1)return 0;
        tot/=2;

        vector<unordered_map<int,int>>dp(n+1);
        function<bool(int,int)>recur=[&](int i, int tot)->bool{
            if(tot==0)return 1;
            if(i>=n || tot<0)return 0;
            if(dp[i].find(tot)!=dp[i].end())
            return dp[i][tot];

            return dp[i][tot]=recur(i+1,tot-A[i]) or recur(i+1,tot);
        };
        return recur(0,tot);
    }
};