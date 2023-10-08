class Solution {
public:
    int maxDotProduct(vector<int>& A, vector<int>& B) {
        int n=A.size(),p=B.size();

        int dp[501][501];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int x, int y){
            if(x==n or y==p) return 0;
            if(dp[x][y]!=-1) return dp[x][y];

            int ans;
            ans=A[x]*B[y]+recur(x+1,y+1);
            ans=max(ans,max(recur(x+1,y),recur(x,y+1)));
            return dp[x][y]=ans;
        };

        int hiA = INT_MIN;
        int hiB = INT_MIN;
        int loA = INT_MAX;
        int loB = INT_MAX;

        
        for (int x : A) {
            hiA = max(hiA, x);
            loA = min(loA, x);
        }
        
        for (int x : B) {
            hiB = max(hiB, x);
            loB = min(loB, x);
        }

        
        if ((hiA < 0 && loB > 0) || (loA > 0 && hiB < 0)) {
            return max(hiA * loB, loA * hiB);
        }
        
        return recur(0,0);
    }
};