class Solution {
public:
    using pI=pair<int,int>;
    int findCheapestPrice(int N,vector<vector<int>>&E,int src,int D,int k){
        vector<pI>adj[N+1];
        for(auto e:E) adj[e[0]].push_back({e[1],e[2]});

        queue<pI>q;
        q.push({src,0});

        vector<int>cost(N,INT_MAX);
        k++;
        while(!q.empty() and k--){
            int sz=q.size();
            while(sz--){
                auto [u,v]=q.front();
                q.pop();

                for(auto [node,price]:adj[u]){
                    if(v+price<cost[node]){
                        cost[node]=v+price;
                        q.push({node,cost[node]});
                    }
                }
            }
        }
        return cost[D]==INT_MAX?-1:cost[D];
    }
};