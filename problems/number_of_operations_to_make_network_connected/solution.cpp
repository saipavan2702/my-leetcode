class Solution {
public:
    int find(int r,int P[]) {
        if(r==P[r])
        return r;

        return find(P[r],P);
    }
    void uni(int u,int v,int P[]) {
        if(u!=v)
        P[u]=v;
    }
    int makeConnected(int n, vector<vector<int>>&T) {
        int k=T.size();

        if(n-1>k)
        return -1;

        int P[n];
        for(int i=0;i<n;i++)
        P[i]=i;


        for(int i=0;i<k;i++){
            int a=find(T[i][0],P);
            int b=find(T[i][1],P);
            uni(a,b,P);
        }

        int cnt=0;
        for(int i=0;i<n;i++){
            if(P[i]==i)
            cnt++;
        }
        return cnt-1;
    }
};