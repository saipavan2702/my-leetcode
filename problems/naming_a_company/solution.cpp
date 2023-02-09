class Solution {
public:
    long long distinctNames(vector<string>& ideas) {
        unordered_set<string> st;
        int n = ideas.size();
        for(string i: ideas) 
            st.insert(i);
        vector<vector<int>> dp(26, vector<int>(26));
        for(int i = 0; i < n; i++) {
            string t = ideas[i];
            for(int j = 0; j < 26; j++) {
                t[0] = (char)('a' + j);
                if(st.find(t) == st.end()) dp[ideas[i][0] - 'a'][j]++;
            }
        }
        long long res = 0;
        for(int i = 0; i < 26; i++)
            for(int j = 0; j < 26; j++) 
                res += dp[i][j] * dp[j][i];
        return res;
    }
};