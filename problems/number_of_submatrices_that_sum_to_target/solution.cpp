class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& grid, int t) {
        int n,p;n=grid.size();
        p=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<p;j++)
            {
              grid[i][j]=grid[i][j]+grid[i][j-1];
            }
        }
        unordered_map<int,int>freq;
        int cnt=0,curr=0;
        for(int i=0;i<p;i++)
        {
            for(int j=i;j<p;j++)
            {
                freq.clear();
                freq[0]=1;
                curr=0;
                for(int r=0;r<n;r++)
                {
                    curr+=grid[r][j]-(i>0?grid[r][i-1]:0);
                    cnt+=freq[curr-t];
                    freq[curr]++;
                }
            }
        }
        return cnt;
    }
};