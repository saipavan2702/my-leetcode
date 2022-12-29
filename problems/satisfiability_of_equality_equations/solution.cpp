class Solution {
public:
    int find(int r,int P[]) {
        if(r!=P[r])
        return find(P[r],P);

        return r;
    }
    void uni(int u, int v, int P[]) {
        int a=find(u,P);
        int b=find(v,P);

        if(a!=b)
        P[b]=a;
    }
    bool equationsPossible(vector<string>& T) {
        int P[27];
        for(int i=0;i<27;i++)
        P[i]=i;

        for(auto&x:T){
           if(x[1]=='!')
           continue;

           int lo=x[0]-'a';
           int hi=x[3]-'a';

           uni(lo,hi,P);
        }
        for(auto&x:T) {
            if(x[1]!='!')
            continue;

            int lo=x[0]-'a';
            int hi=x[3]-'a';

            int p=find(lo,P);
            int q=find(hi,P);
            
            if(p==q)
            return 0;
        }
        return 1;
    }
};