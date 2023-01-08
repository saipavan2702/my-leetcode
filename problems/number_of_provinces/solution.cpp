class Solution {
public:
    int find(int r,int P[]){
        if(r==P[r])
        return r;

        return find(P[r],P);
    }
    void uni(int u,int v,int P[]){
        if(u!=v)
        P[u]=v;
    }
    int findCircleNum(vector<vector<int>>& E) {
        int n=E.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(E[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int P[n];
        for(int i=0;i<n;i++)
        P[i]=i;

        for(int i=0;i<n;i++){
            for(int x:adj[i]){
                int a=find(x,P);
                int b=find(i,P);
                uni(a,b,P);
            }
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            if(P[i]==i)
            cnt++;
        }
        return cnt;
    }
};