class Solution {
public:
    bool canFinish(int N, vector<vector<int>>& R) {
        vector<int>indeg(N);
        vector<int>adj[N+1];
        for(auto &x:R){
            adj[x[0]].push_back(x[1]);
        }
        for(auto &x:R) indeg[x[1]]++;

        queue<int>q;
        for(int i=0;i<N;i++) if(indeg[i]==0) q.push(i);

        int cn=0;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            cn++;

            for(auto node:adj[u]){
                indeg[node]--;
                if(indeg[node]==0)q.push(node);
            }
        }
        return cn==N;
    }
};