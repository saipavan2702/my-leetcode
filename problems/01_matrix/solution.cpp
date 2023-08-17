class Solution {
public:
    vector<int> dir = {0, 1, 0, -1, 0};
    using pI=pair<int,int>;

    vector<vector<int>> updateMatrix(vector<vector<int>>& G) {
        int n=G.size(), p=G[0].size();
        queue<pI>q;
        for (int r=0;r<n;r++)
            for (int c=0;c<p;c++)
                if(G[r][c] == 0) q.push({r,c});
                else G[r][c] = -1; 

        while (!q.empty()) {
            auto [r, c] = q.front(); q.pop();
            for (int i=0;i<4;i++) {
                int nr=r+dir[i], nc=c+dir[i+1];
                if(nr<0 || nr==n || nc<0 || nc==p || G[nr][nc]!=-1) continue;
                G[nr][nc]=G[r][c]+1;
                q.push({nr,nc});
            }
        }
        return G;
    }
};
