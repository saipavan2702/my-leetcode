class Solution {
public:
    vector<int> findOrder(int N, vector<vector<int>>& R) {
        vector<int>indeg(N);
        vector<int>adj[N+1];
        for(auto &x:R){
            adj[x[1]].push_back(x[0]);
        }
        for(auto &x:R) indeg[x[0]]++;

        queue<int>q;
        vector<int>Q;
        for(int i=0;i<N;i++) if(indeg[i]==0) q.push(i);

        int cn=0;
        while(!q.empty()){
            auto u=q.front();
            q.pop();
            Q.push_back(u);

            for(auto node:adj[u]){
                indeg[node]--;
                if(indeg[node]==0)q.push(node);
            }
        }
        if(Q.size()==N)
        return Q;

        return {};
    }
};