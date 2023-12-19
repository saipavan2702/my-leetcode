class Solution {
public:
    public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& G) {
        int m = G.size();
        int n = G[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));

        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                res[i][j] = recur(G, i, j);
            }
        }

        return res;
    }

private:
    int recur(const vector<vector<int>>& G, int x, int y) {
        int m = G.size();
        int n = G[0].size();
        int sum = 0;
        int count = 0;

        for (int i = -1; i <= 1; ++i) {
            for (int j = -1; j <= 1; ++j) {
                int nx = x + i;
                int ny = y + j;
                if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
                    sum += G[nx][ny];
                    ++count;
                }
            }
        }

        return sum / count;
    }
};