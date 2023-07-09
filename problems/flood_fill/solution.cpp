class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& ig, int sr, int sc, int color) {

        int pre=ig[sr][sc];
        function<void(int,int)>dfs=[&](int x, int y){
            if(x<0 or x>=ig.size() or y<0 or y>=ig[0].size() or ig[x][y]!=pre or ig[x][y]==color)return;

            ig[x][y]=color;
            dfs(x-1,y);
            dfs(x+1,y);
            dfs(x,y+1);
            dfs(x,y-1);
        };
        dfs(sr,sc);
        return ig;
    }
};