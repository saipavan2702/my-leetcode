class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>&grid) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        unordered_map<int,vector<int>>freq;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<p;j++)
            {
              freq[i-j].push_back(grid[i][j]);
            }
        }
        for(int i=-(p-1);i<n;i++)
        {
            sort(freq[i].begin(),freq[i].end());
        }
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=p-1;j>=0;j--)
            {
                grid[i][j]=freq[i-j].back();
                freq[i-j].pop_back();
            }
        }
        return grid;
    }
};