class Solution {
public:
    vector<vector<int>>req;
    void recur(vector<int>&vis, vector<vector<int>>& T,int i,vector<int>&ret) {
        int n;
        n=T.size();
        
        if(i==n-1){
            req.push_back(ret);
            return;
        }
        for(int u:T[i]) {
            
            if(!vis[u]) {
              vis[u]=1;
              ret.push_back(u);
              recur(vis,T,u,ret);
              ret.pop_back();
              vis[u]=0;
            }
            
        }

    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& T) {
        int n;
        n=T.size();

        vector<int>vis(n,0);
        vector<int>ret;
        ret.push_back(0);
        
        recur(vis,T,0,ret);
        return req;
    }
};