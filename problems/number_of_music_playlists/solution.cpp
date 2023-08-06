class Solution {
public:
    using ll=long long;
    int numMusicPlaylists(int n, int goal, int k) {
        const int MOD=1e9+7;
        vector<vector<int>> dp(n + 1, vector<int>(goal + 1, -1));
        function<int(int,int)>recur=[&](int n, int g){
            if(g==0 and n==0) return 1;
            if(n==0 or g==0) return 0;
            if(dp[n][g]!=-1) return dp[n][g];

            return dp[n][g]=((ll)recur(n-1,g-1)*n+(ll)recur(n,g-1)*max(n-k,0))%MOD;
        };
        return recur(n,goal);
    }
};