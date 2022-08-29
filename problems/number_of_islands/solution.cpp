class Solution {
public:
    void dfs(int x,int y,vector<vector<char>>& grid)
    {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        if(x<0 or y<0 or x>=n or y>=p or grid[x][y]=='0')
        return;
        
        grid[x][y]='0';
        dfs(x,y-1,grid);
        dfs(x+1,y,grid);
        dfs(x-1,y,grid);
        dfs(x,y+1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int n,p,cnt=0;
        n=grid.size();
        p=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p;j++)
            {
                if(grid[i][j]=='1')
                {
                 dfs(i,j,grid);
                 cnt++;
                }
            }
        }
        return cnt;
    }
};