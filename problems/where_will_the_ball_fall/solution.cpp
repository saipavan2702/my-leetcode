class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        
        vector<int>ans(p);
        for(int i=0;i<p;i++)
        {
            int r=0,l=i;
            while(r<n)
            {
                if(grid[r][l]==1)
                {
                    if(l+1>=p or grid[r][l+1]==-1)
                    {
                        ans[i]=-1;
                        break;
                    }
                    l++;
                }
                else if(grid[r][l]==-1)
                {
                    if(l<1 or grid[r][l-1]==1)
                    {
                        ans[i]=-1;
                        break;
                    }
                    l--;
                }
                r++;
            }
            if(r==n)
            ans[i]=l;
        }
        return ans;
    }
};