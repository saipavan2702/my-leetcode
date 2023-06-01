class Solution {
public:
    

    int shortestPathBinaryMatrix(vector<vector<int>>& G) {
        int n=G.size();

        if(G[0][0] || G[n-1][n-1])
        return -1;

        queue<pair<int,int>>q;
        q.push({0,0});
        G[0][0]=1;

        while(!q.empty()){
            auto node=q.front();
            q.pop();

            int x=node.first;
            int y=node.second;

            int dx[8]={0,0,1,1,1,-1,-1,-1};
            int dy[8]={-1,1,0,1,-1,0,1,-1};

            for(int i=0;i<8;i++){
                int u=x+dx[i];
                int v=y+dy[i];
                
                if(u>=0 && v>=0 && u<n && v<n && !G[u][v]) {
                    q.push({u,v});
                    G[u][v]=1+G[x][y];

                    if(u==n-1 && v==n-1)
                    return G[u][v];
                }
            }    
        }
        return G[n-1][n-1]?G[n-1][n-1]:-1;
       
    }
};