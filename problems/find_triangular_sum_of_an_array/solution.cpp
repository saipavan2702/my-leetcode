class Solution {
public:
    int triangularSum(vector<int>& grid) {
        int n;n=grid.size();
        vector<int>res(n);
        while(n!=1)
        {
          for(int i=0;i<n-1;i++)
          {
           grid[i]=grid[i]+grid[i+1];
           grid[i]=grid[i]%10;
          }
            n--;
        }
       
        return grid[0];
    }
};