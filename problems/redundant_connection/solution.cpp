class Solution {
public:
    int find(int r,int P[]){
        if(r==P[r])
        return r;

        return P[r]=find(P[r],P);
    }
    bool uni(int u, int v, int P[]){
        if(u!=v)
        P[u]=v;

        return u==v;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& E) {
        int n=E.size();
        int P[n+1];
        for(int i=0;i<=n;i++)
        P[i]=i;

        vector<int>req;
        for(auto x:E){
            int a=find(x[0],P);
            int b=find(x[1],P);
            if(uni(a,b,P))
            req=x;
        }
        return req;
    }
};