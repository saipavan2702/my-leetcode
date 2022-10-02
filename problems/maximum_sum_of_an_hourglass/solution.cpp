class Solution {
public:
    int maxSum(vector<vector<int>>& grid) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        int ans=INT_MIN;
        for(int i=0;i<n-2;i++)
        {
            for(int j=0;j<p-2;j++)
            {
                int s=(grid[i][j]+grid[i][j+1]+grid[i][j+2]+grid[i+1][j+1]+grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]);
                ans=max(s,ans);
            }
        }
        return ans;
    }
};