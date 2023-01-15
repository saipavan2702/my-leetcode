class Solution {
public:
   int find(int r, int P[]){
       if(P[r]==r)
       return r;

       return P[r]=find(P[r],P);
   }
//    void uni(int u, int v, int P[]){
//        if(u!=v)
//        P[u]=v;
//    }
    int numberOfGoodPaths(vector<int>& val, vector<vector<int>>& E) {
        int n=val.size();
        int P[n];
        vector<pair<int,int>>T(n);
        for(int i=0;i<n;i++)
        P[i]=i,T[i]={val[i],1};

        int req=n;
        sort(E.begin(),E.end(),[&](vector<int>&x,vector<int>&y){
        int l=max(val[x[0]],val[x[1]]);
        int r=max(val[y[0]],val[y[1]]);

        return l<r;
        });
        for(auto e:E){
            int a=find(e[0],P);
            int b=find(e[1],P);
            if(T[a].first!=T[b].first){
                if(T[a].first>T[b].first)
                P[b]=a;
                else
                P[a]=b;
            }
            else{
                P[a]=b;
                req+=T[a].second*T[b].second;
                T[b].second+=T[a].second;
            }
        }
        return req;
    }
};