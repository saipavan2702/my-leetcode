class Solution {
public:
    int find(int r,int P[]) {
        if(r==P[r])
        return r;

        return find(P[r],P);
    }
    void uni(int u,int v,int P[]){
        if(u!=v)
        P[u]=v;
    }
    int removeStones(vector<vector<int>>& T) {
        int n=T.size();

        int cnt=0;
        int P[n];
        for(int i=0;i<n;i++)
        P[i]=i;

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(T[i][0]==T[j][0] || T[i][1]==T[j][1]){
                    int a=find(i,P);
                    int b=find(j,P);
                    uni(a,b,P);
                }
            }
        }
        for(int i=0;i<n;i++){
            if(P[i]==i)
            cnt++;
        }
        return n-cnt;
    }
};