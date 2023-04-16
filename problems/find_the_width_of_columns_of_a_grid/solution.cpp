class Solution {
public:
    vector<int> findColumnWidth(vector<vector<int>>& grid) {
        int n=grid.size();
        int p=grid[0].size();
        
        vector<int>ans(p);
        for(int i=0;i<p;i++){
            int res=0;
            for(int j=0;j<n;j++){
                string k=to_string(grid[j][i]);
                
                int sz=k.size();
                res=max(sz,res);
            }
            ans[i]=res;
        }
        
        return ans;
    }
};