class Solution {
public:
    bool canJump(vector<int>& A) {
        int n=A.size();
        if(n==1)return 1;
        
        // int l=0,ret=0;
        // while(l<=ret){
        //    ret=max(ret,l+nums[l]);
        //    if(ret>=n-1)
        //    return 1;

        //    l++;
        // }
        // return 0;

        int dp[10005];
        memset(dp,-1,sizeof(dp));
        function<bool(int)>recur=[&](int i)->bool{
            if(A[i]>=n-1 || i>=n-1)return 1;
            if(A[i]==0)return 0;

            if(dp[i]!=-1)return dp[i];
            
            for(int k=i+1;k<=A[i]+i;k++){
                if(recur(k))
                return dp[i]=1;
            }
            return dp[i]=0;
        };
        return recur(0);
    }
};