class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {
        int n=p.size();
        sort(p.begin(),p.end(),[&](vector<int>a, vector<int>b){
            return a[1]<b[1];
        });

        int dp[1005][1005];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int i, int pre){
            if(i==n) return 0;
            if(dp[i][pre+1]!=-1)return dp[i][pre+1];

            int ans=0;
            if(pre==-1 or p[i][0]>p[pre][1])
            ans=1+recur(i+1,i);

            ans=max(ans,recur(i+1,pre));
            return dp[i][pre+1]=ans;
        };
        return recur(0,-1);
    }
};