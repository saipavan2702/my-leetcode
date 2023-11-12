class Solution {
public:
    int numBusesToDestination(vector<vector<int>>&R, int S, int T) {
        unordered_map<int,vector<int>>adj;
        for(int i=0;i<R.size();i++)
            for(int x:R[i]) adj[x].push_back(i);
        
        using pI=pair<int,int>;
        queue<pI>q;
        unordered_set<int>seen;
        seen.insert(S);
        q.push({S,0});

        while(!q.empty()){
            auto [x,y]=q.front();q.pop();
            if(x==T) return y;
            for(int i:adj[x]){
               for(int u:R[i]){
                   if(seen.find(u)==seen.end()){
                       seen.insert(u);
                       q.push({u,y+1});
                   }
               }
               R[i].clear();
            }
        }
        return -1;
    }
};