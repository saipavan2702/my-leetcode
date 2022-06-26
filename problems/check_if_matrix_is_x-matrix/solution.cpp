class Solution {
public:
    bool checkXMatrix(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[0].size();j++)
            {
                if(i==j and grid[i][j]==0)
                    return 0;
                else if(i+j==grid.size()-1 and grid[i][j]==0)
                    return 0;
                else if(i!=j and i+j!=grid.size()-1 and grid[i][j]!=0)
                    return 0;
            }
        }
        return 1;
    }
};