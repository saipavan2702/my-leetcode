class Solution {
public:
    int dfs(vector<vector<int>>& grid,int x,int y)
    {
    int n,p;n=grid.size();
    p=grid[0].size();
    if(x<0 or y<0 or x>n-1 or y>p-1 or grid[x][y]==0)
    return 0;
    
    
    grid[x][y]=0;
    return 1+ dfs(grid,x+1,y)+dfs(grid,x,y-1)+dfs(grid,x-1,y)+dfs(grid,x,y+1);

    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
         int n,p,cnt=0,res=0;n=grid.size();
    p=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(grid[i][j]==1)
            {
                cnt= dfs(grid,i,j);
            }
            res=max(cnt,res);
        }
    }
    
    return res;
    }
};