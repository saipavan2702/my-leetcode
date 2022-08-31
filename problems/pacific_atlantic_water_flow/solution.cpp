class Solution {
public:
    vector<vector<int>>res;
    vector<vector<bool>>a,b;
    void dfs(vector<vector<int>>&heights,int x,int y,vector<vector<bool>>&vis)
    {
        int n,p;
        n=heights.size();
        p=heights[0].size();
        if(vis[x][y])
        return;
        
        vis[x][y]=1;
        
        if(a[x][y] and b[x][y])
        res.push_back(vector<int>{x,y});
        
        if(x+1<n && heights[x+1][y]>=heights[x][y])
        dfs(heights,x+1,y,vis); 
        if(x-1>=0 && heights[x-1][y]>=heights[x][y])
        dfs(heights,x-1,y,vis); 
        if(y+1<p && heights[x][y+1]>=heights[x][y])
        dfs(heights,x,y+1,vis); 
        if(y-1>=0 && heights[x][y-1]>=heights[x][y])
        dfs(heights,x,y-1,vis); 
        
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
       int n,p;
        n=heights.size();
        if(n==0)
        return res;
        
        p=heights[0].size();
        a=b=vector<vector<bool>>(n,vector<bool>(p,0));
        for(int i=0;i<n;i++)
        {
            dfs(heights,i,0,a);
            dfs(heights,i,p-1,b);
        }
        for(int i=0;i<p;i++)
        {
            dfs(heights,0,i,a);
            dfs(heights,n-1,i,b);
        }
        return res;
    }
};