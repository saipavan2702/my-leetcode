class Solution {
public:
    int maxUncrossedLines(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int p=B.size();

        int dp[505][505];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int i, int j){
            if(i>=n || j>=p)
            return 0;

            if(dp[i][j]!=-1)
            return dp[i][j];

            int cnt=0,a=0,b=0;
            if(A[i]==B[j])
            cnt=1+recur(i+1,j+1);
            else{
                a=recur(i,j+1);
                b=recur(i+1,j);
            }
            return dp[i][j]=max({cnt,a,b});
        };

        return recur(0,0);
    }
};