class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
    int i, j;
    for (i = 0; i <n-1; i++) {
        for (j =0; j<m-1; j++) {
            if (matrix[i][j] != matrix[i+1][j+1]) {
                return false;
            }
        }
    }
    return true;
    }
};