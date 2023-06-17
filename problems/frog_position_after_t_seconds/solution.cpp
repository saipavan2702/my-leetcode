class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& E, int t, int Target) {
        vector<int>graph[n+1];
        for(auto e:E) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }
        int sz[105]={0};
        sz[1]=graph[1].size();

        for(int i=2;i<=n;i++)
        sz[i]=graph[i].size()-1;

        function<double(int,int,int)>recur=[&](int node, int prev, int t)->double{
            if(t==0 || sz[node]==0)
            return Target==node;
            
            double cn=0.0;
            for(auto i:graph[node]){
                if(i==prev)
                continue;

                cn+=recur(i,node,t-1);
            }
            cn*=(1.0/sz[node]);
            return cn;
        };
        return recur(1,0,t);
        
        
    }
};