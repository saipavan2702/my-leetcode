class Solution {
public:
    bool searchMatrix(vector<vector<int>>&grid, int t) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        int l=0,r=p-1;
        while(l<n and r>=0)
        {
            if(grid[l][r]<t)
                l++;
            else if(grid[l][r]>t)
                r--;
            else if(grid[l][r]==t)
            return 1;
        }
        return 0;
    }
};