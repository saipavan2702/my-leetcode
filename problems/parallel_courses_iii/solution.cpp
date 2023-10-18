class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& R, vector<int>& T) {
        vector<int>indeg(n,0);
        vector<int>adj[n];
        for(auto x:R){
            adj[x[0]-1].push_back(x[1]-1);
            indeg[x[1]-1]++;
        }
        queue<int>q;
        vector<int>D(n,0);
        for(int i=0;i<n;i++) if(indeg[i]==0) q.push(i),D[i]=T[i];
        
        while(!q.empty()){
            int u=q.front();q.pop();
    
            for(auto x:adj[u]){
                indeg[x]--;
                D[x]=max(D[u]+T[x],D[x]);
                if(indeg[x]==0) q.push(x);
            }
            
        }
        return *max_element(D.begin(),D.end());
    }
};