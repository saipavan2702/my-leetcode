class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int p=cuts.size();
        sort(cuts.begin(),cuts.end());

        int dp[102][102];
        memset(dp,-1,sizeof(dp));

        function<int(int,int,int,int)>recur=[&](int sI, int eI, int Lh, int Rh){
            if(sI>eI)
            return 0;

            if(dp[sI][eI]!=-1)
            return dp[sI][eI];

            int need=1e9;
            for(int i=sI;i<=eI;i++){
                int lC=recur(sI,i-1,Lh,cuts[i]);
                int rC=recur(i+1,eI,cuts[i],Rh);

                need=min(need,abs(Lh-Rh)+lC+rC);
            }
            return dp[sI][eI]=need;
        };

        return recur(0,p-1,0,n);
    }
};