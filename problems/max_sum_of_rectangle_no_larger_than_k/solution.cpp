class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& grid, int k) {
        int n,p;
        n=grid.size();
        p=grid[0].size();
        for(int i=0;i<n;i++)
        {
            for(int j=1;j<p;j++)
            {
                grid[i][j]+=grid[i][j-1];
            }
        }
        int res=INT_MIN;
        for(int i=0;i<p;i++)
        {
            for(int j=i;j<p;j++)
            {
                set<int>st;
                st.insert(0);
                int pref=0;
                for(int r=0;r<n;r++)
                {
                    int curr=grid[r][j]-(i==0?0:grid[r][i-1]);
                    pref+=curr;
                    
                    auto x=st.lower_bound(pref-k);
                    if(x!=st.end())
                    res=max(res,pref-*x);
                    
                    st.insert(pref);
                }
            }
        }
        return res;
    }
};