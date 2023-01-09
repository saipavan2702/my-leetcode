class Solution {
public:
    int find(int r,int P[]){
        if(r==P[r])
        return r;

        return P[r]=find(P[r],P);
    }
    void uni(int u, int v, int P[]){
        if(u!=v)
        P[find(u,P)]=find(v,P);
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& E) {
        int n=E.size();
        unordered_map<string,int>dict;
        int P[n+1];
        for(int i=0;i<n;i++)
        P[i]=i;

        for(int i=0;i<n;i++) {
            for(int j=1;j<E[i].size();j++) {
                if(dict.find(E[i][j])==dict.end())
                dict[E[i][j]]=i;
                else
                uni(i,dict[E[i][j]],P);
            }
        }
        unordered_map<int,vector<string>>req;
        vector<vector<string>>py;
        for(auto f:dict){
            req[find(f.second,P)].push_back(f.first);
        }
        for(auto x:req){
            auto M=x.second;
            sort(M.begin(),M.end());
            M.insert(M.begin(),E[x.first][0]);
            py.push_back(M);
        }
        return py;
    }
};