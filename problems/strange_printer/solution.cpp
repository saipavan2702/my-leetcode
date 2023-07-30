class Solution {
public:
    int strangePrinter(string s) {
        int n=s.size();
        int dp[105][105];
        memset(dp,-1,sizeof(dp));

        function<int(int,int)>recur=[&](int i, int j){
            if(i==j) return dp[i][j]=1;
            if(dp[i][j]!=-1) return dp[i][j];

            int cn;
            if(s[i]==s[j] or s[j-1]==s[j]) cn=recur(i,j-1);
            else if(s[i]==s[i+1]) cn=recur(i+1,j);
            else{
                cn=1+recur(i,j-1);
                for(int k=i+1;k<j;k++){
                    if(s[k]==s[j]) cn=min(cn, recur(i,k-1)+recur(k,j-1));
                }
            }
            return dp[i][j]=cn;
        };
        return recur(0,n-1);
    }
};