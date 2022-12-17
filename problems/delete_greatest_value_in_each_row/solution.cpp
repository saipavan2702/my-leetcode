class Solution {
public:
    int deleteGreatestValue(vector<vector<int>>& grid) {
        int ans=0;
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        for(int i=0;i<n;i++)
        sort(grid[i].begin(),grid[i].end());
        
        for(int j=0;j<p;j++)
        {
            int ret=INT_MIN;
            for(int i=0;i<n;i++)
            ret=max(ret,grid[i][j]);
            
            ans+=ret;
        }
        return ans;
    }
};