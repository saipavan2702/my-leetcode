class Solution {
public:
    bool wordBreak(string s, vector<string>& D) {
        int n=s.size();
        unordered_set<string>st(D.begin(),D.end());
        vector<int>dp(n+1,-1);

        function<bool(int,string)>recur=[&](int x, string s)->bool{
            int n=s.size();
            if(x==n)    return 1;
            if(dp[x]!=-1)return dp[x];

            for(int i=x;i<n;i++){
                if(recur(i+1,s) and st.find(s.substr(x,i+1-x))!=st.end())
                return dp[x]=1;
            }
            return dp[x]=false;
        };
        return recur(0,s);
    }
};