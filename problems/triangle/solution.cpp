class Solution {
public:
    int minimumTotal(vector<vector<int>>& tri) {
        int n;
        n=tri.size();
        for(int i=n-2;i>=0;i--)
        {
            for(int j=0;j<tri[i].size();j++)
            {
                tri[i][j]=tri[i][j]+min(tri[i+1][j],tri[i+1][j+1]);
            }
        }
        return tri[0][0];
    }
};