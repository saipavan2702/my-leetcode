class Solution {
public:
    bool PredictTheWinner(vector<int>& A) {
        int n=A.size();
        int tot=accumulate(begin(A),end(A),0);

        int dp[25][25];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int x, int y){
            if(x>y) return 0;
            if(dp[x][y]!=-1) return dp[x][y];

            int op1=A[x]+min(recur(x+2,y),recur(x+1,y-1));
            int op2=A[y]+min(recur(x,y-2),recur(x+1,y-1));

            return dp[x][y]=max(op1,op2);
        };
        int p=recur(0,n-1);
        int q=tot-p;
        return p>=q;
    }
};