class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int n=grid.size();
        int p=grid[0].size();
        int cnt=0;

        auto test=[&](vector<int>h){
            int lo(0),hi(p-1);

            int idx=-1;
            while(lo<=hi){
                int u=(lo+hi)/2;
                if(h[u]<0)
                idx=u,hi=u-1;
                else
                lo=u+1;
            }
            return idx==-1?0:p-idx;
        };

        for(int i=0;i<n;i++){
            cnt+=test(grid[i]);
        }
        return cnt;
    }
};