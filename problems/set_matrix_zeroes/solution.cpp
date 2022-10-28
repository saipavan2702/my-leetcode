class Solution {
public:
    void setZeroes(vector<vector<int>>&grid) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        bool r=1;
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
                r=0;
            for(int j=1;j<p;j++)
            {
                if(grid[i][j]==0)
                grid[i][0]=grid[0][j]=0;
            }
        }
        for(int i=n-1;i>=0;i--)
        {
            for(int j=p-1;j>=1;j--)
            {
                if(grid[i][0]==0 or grid[0][j]==0)
                    grid[i][j]=0;
            }
            if(!r)
            grid[i][0]=0;
        }
    }
};