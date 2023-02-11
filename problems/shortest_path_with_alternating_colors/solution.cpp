class Solution {
public:
    using pI=pair<int,int>;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>&R,vector<vector<int>>&B) {
        vector<int>Q(n,-1);
        
        vector<vector<pI>>adj(n);
        for(auto x:R)
        adj[x[0]].push_back({x[1],1});

        for(auto x:B)
        adj[x[0]].push_back({x[1],-1});

        queue<tuple<int,int,int>>q;
        q.push(make_tuple(0,0,0));
        Q[0]=0;

        while(!q.empty()) {
            auto x=q.front();
            q.pop();

            int node=get<0>(x);
            int d=get<1>(x);
            int c=get<2>(x);

            for(auto&u:adj[node]) {
                if(u.second!=c and u.first!=-1) {

                    if(Q[u.first]==-1)
                    Q[u.first]=d+1;

                    q.push(make_tuple(u.first,d+1,u.second));
                    u.first=-1;
                }
            }
        }
        return Q;
    }
};