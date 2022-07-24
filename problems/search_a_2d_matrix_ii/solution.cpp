class Solution {
public:
    bool searchMatrix(vector<vector<int>>& grid, int target) {
        int n,p;n=grid.size();p=grid[0].size();
            int r,l;r=p-1;l=0;
            while(l<n and r>=0)
            {
                if(grid[l][r]==target)
                return 1;
                else if(grid[l][r]>target)
                r--;
                else
                l++;
            }
        return 0;
    }
};