class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int n=grid.size();
        int p=grid[0].size();

        function<void(int,int)>dfs=[&](int x, int y){
            if(x<0 || x>=n || y<0 || y>=p)
            return;

            if(grid[x][y]==0)
            return;

            grid[x][y]=0;
            dfs(x-1,y);
            dfs(x+1,y);
            dfs(x,y-1);
            dfs(x,y+1);
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if((i==0 || i==n-1 || j==0 || j==p-1) and grid[i][j]==1){
                    dfs(i,j);
                }
            }
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(grid[i][j]==1)
                cnt++;
            }
        }
        return cnt;
    }
};