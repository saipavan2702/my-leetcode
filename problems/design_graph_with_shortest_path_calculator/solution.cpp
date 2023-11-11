class Graph {
public:
    using pI=pair<int,int>;
    
    vector<vector<pI>>adj;
    Graph(int n, vector<vector<int>>&E) {
        adj.resize(n);
        
        for(auto e:E)
            adj[e[0]].push_back({e[1],e[2]});
    }
    
    void addEdge(vector<int> e) {
        adj[e[0]].push_back({e[1],e[2]});
    }
    
    int shortestPath(int S, int D) {
        int n=adj.size();
        
        set<pI>st;
        st.insert({0,S});
        
        vector<int>dist(n,1e9);
        dist[S]=0;
        
        while(!st.empty()){
            auto it=*st.begin();
            int x=it.second;
            int d=it.first;
            
            st.erase(it);
            for(auto u:adj[x]){
                int dt=u.second;
                int vet=u.first;
                
                if(d+dt<dist[vet]){
                    dist[vet]=d+dt;
                    st.insert({dist[vet],vet});
                }
            }
        }
        return dist[D]==1e9?-1:dist[D];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */