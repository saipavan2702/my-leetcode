class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n,cnt=0;n=grid.size();
        for(int i=0;i<n;i++)
        {
          vector<int>s;
          for(int j=0;j<n;j++)
          {
              s.push_back(grid[j][i]);
          }
          cnt+=count(begin(grid),end(grid),s);
        }
        return cnt;
    }
};