class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
         int n=grid.size();
    int p=grid[0].size();

    function<void(int,int)>dfs=[&](int x,int y){
        if(x<0 || x>=n || y<0 || y>=p || grid[x][y])
        return;

        grid[x][y]=1;
        dfs(x-1,y);
        dfs(x+1,y);
        dfs(x,y-1);
        dfs(x,y+1);

    };

    int cnt=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            if(grid[i][j]==0 and (i==n-1 || i==0 || j==0 || j==p-1)){
                dfs(i,j);
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<p;j++){
            if(grid[i][j]==0){
                dfs(i,j);
                cnt++;
            }
        }
    }
    cout<<cnt<<endl;
    return cnt;
        
    }
};