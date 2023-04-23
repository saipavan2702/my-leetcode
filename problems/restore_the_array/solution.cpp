class Solution {
public:
    int numberOfArrays(string s, int k) {
        int cnt=0;
        int n=s.size();
        vector<int>dp(n,-1);

        function<int(int)>recur=[&](int x)->int{
            if(x==n)
            return 1;

            if(s[x]=='0')
            return 0;

            if(dp[x]!=-1)
            return dp[x];
            
            long have=0;
            int can=0;
            for(int i=x;i<n;i++){
                have=have*10+s[i]-'0';
                if(have>k)
                break;

                can=(can+recur(i+1))%1000000007;
            }
            return dp[x]=can;
        };
        return recur(0);
    }
};