class Solution {
public:
    string stoneGameIII(vector<int>& V) {
        int n=V.size();
        vector<int>dp(n,-1);

        int a=0,b=0;
        function<int(int)>recur=[&](int x){
            if(x>=n)
            return 0;

            if(dp[x]!=-1)
            return dp[x];

            int p,q,r;
            p=q=r=-1e9;

            p=V[x]-recur(x+1);

            if(x+1<n)
            q=V[x]+V[x+1]-recur(x+2);

            if(x+2<n)
            r=V[x]+V[x+1]+V[x+2]-recur(x+3);

            return dp[x]=max(p,max(q,r));
    
        };
        int h=recur(0);
        if(h==0)
        return "Tie";
        
        return h>0?"Alice":"Bob";

    }
};