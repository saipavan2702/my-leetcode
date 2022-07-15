class Solution {
public:
    void dfs(vector<vector<int>>& grid,int x,int y)
    {
    int n,p;n=grid.size();
    p=grid[0].size();
    if(x<0 or y<0 or x>n-1 or y>p-1 or grid[x][y]==1)
    return;
    
    
    grid[x][y]=1;
    dfs(grid,x+1,y);
    dfs(grid,x,y-1);
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
    }
    int closedIsland(vector<vector<int>>& grid) {
         int n,p,cnt=0;n=grid.size();
    p=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if((i==0 or i==n-1 or j==0 or j==p-1) and grid[i][j]==0)
            {
                dfs(grid,i,j);
            }
        }
    }
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(grid[i][j]==0)
            {
                cnt++;
                dfs(grid,i,j);
            }
        }
    }
    

    return cnt;
    }
};