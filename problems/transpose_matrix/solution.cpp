class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>>&G) {
        int n=G.size(),p=G[0].size();

        vector<vector<int>>ans(p,vector<int>(n));
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                ans[j][i]=G[i][j];
            }
        }
        return ans;
    }
};