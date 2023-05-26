class Solution {
public:
    int stoneGameII(vector<int>& P) {
        int n=P.size();
        int dp[200][200][2];
        memset(dp,-1,sizeof(dp));

        function<int(int,int,int)>recur=[&](int x, int hi, int turn){
            if(x==n)
            return 0;

            if(dp[x][hi][turn]!=-1)
            return dp[x][hi][turn];

            int have=0;
            int need=(turn==0)?0:1e9;
            for(int i=1;i<=2*hi;i++){
                int idx=x+i-1;

                if(idx>=n)
                break;

                have+=P[idx];
                
                if(turn==0)
                need=max(need,have+recur(idx+1,max(hi,i),1));
                else
                need=min(need,recur(idx+1,max(hi,i),0));
            }
            return dp[x][hi][turn]=need;
        };

        return recur(0,1,0);
    }
};