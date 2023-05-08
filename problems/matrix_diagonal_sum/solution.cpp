class Solution {
public:
    int diagonalSum(vector<vector<int>>& G) {
        return accumulate(G.begin(), G.end(), 0, 
        [&](int curr, const vector<int>& row) {
                int i = &row - &G[0]; 
                int n=G.size();
                return curr+row[i]+row[n-i-1]*(i!=n-i-1);
            });
    }
};