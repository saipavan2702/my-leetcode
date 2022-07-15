class Solution {
public:
    void dfs(vector<vector<char>>& grid,int x,int y)
{
    int n,p;n=grid.size();
    p=grid[0].size();
    if(x<0 or y<0 or x>n-1 or y>p-1 or grid[x][y]=='0')
    return;
    
    
    grid[x][y]='0';
    dfs(grid,x+1,y);
    dfs(grid,x,y-1);
    dfs(grid,x-1,y);
    dfs(grid,x,y+1);
}
    int numIslands(vector<vector<char>>& grid) {
        int n,p,cnt=0;n=grid.size();
    p=grid[0].size();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<p;j++)
        {
            if(grid[i][j]=='1')
            {
                dfs(grid,i,j);
                cnt++;
            }
        }
    }
    return cnt;
    }
};