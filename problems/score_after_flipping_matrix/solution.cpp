class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        int n,p,cnt,res=0;
        n=grid.size();
        p=grid[0].size();
        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==0)
            {for(int j=0;j<p;j++)
              grid[i][j]=!grid[i][j];}
        }
        for(int j=0;j<p;j++)
        {
            cnt=0;
            for(int i=0;i<n;i++)
            {
                if(grid[i][j])
                cnt++;
            }
            res+=(max(cnt,n-cnt)*pow(2,(p-1-j)));
        }
        return res;
    }
};