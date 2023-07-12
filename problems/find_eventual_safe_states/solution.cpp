class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int N=graph.size();
        vector<int>outdeg(N+1);
        vector<int>adj[N+1];

        for(int i=0;i<N;i++){
            outdeg[i]=graph[i].size();
            for(auto x:graph[i]){
                adj[x].push_back(i);
            }
        }

        vector<int>an;
        queue<int>q;
        for(int i=0;i<N;i++) if(outdeg[i]==0)q.push(i);

        while(!q.empty()){
            auto u=q.front();q.pop();
            an.push_back(u);
            for(auto node:adj[u]){
                outdeg[node]--;
                if(outdeg[node]==0)q.push(node);
            }
        }
        sort(begin(an),end(an));
        return an;
    }
};