class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n;
        n=grid.size();
        vector<vector<int>>res(n-2,vector<int>(n-2,0));
        for(int i=1;i<=n-2;i++)
        {
            for(int j=1;j<=n-2;j++)
            {
                 int sus=0;
                sus=max({sus,grid[i-1][j-1],grid[i-1][j],grid[i-1][j+1]});
                sus=max({sus,grid[i][j-1],grid[i][j],grid[i][j+1]});
                sus=max({sus,grid[i+1][j-1],grid[i+1][j],grid[i+1][j+1]});
                res[i-1][j-1]=sus;
            }
        }
        return res;
        
    }
};