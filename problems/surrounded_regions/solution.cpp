class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y)
    {
    int n,p;n=grid.size();
    p=grid[0].size();
    if(x<0 or y<0 or x>=n or y>=p or grid[x][y]!='O')
    return;
    
    
    grid[x][y]='*';
    dfs(grid,x+1,y);
    dfs(grid,x,y-1);
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
    }
    void solve(vector<vector<char>>& grid) {
        int n,p;n=grid.size();
    p=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if((i==0 or i==n-1 or j==0 or j==p-1) and grid[i][j]=='O')
            {
                dfs(grid,i,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(grid[i][j]=='O')
            grid[i][j]='X';
            else if(grid[i][j]=='*')
            grid[i][j]='O';
        }
    }
    

   
    }
};