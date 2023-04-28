class Solution {
public:
    int find(int r, int P[]){
        if(P[r]==r)
        return r;

        return P[r]=find(P[r],P);
    }
    void uni(int u, int v, int P[]){
        int a=find(u,P);
        int b=find(v,P);

        if(a!=b)
        P[a]=b;
    }
    int numSimilarGroups(vector<string>& S) {
        int n=S.size();
        int p=S[0].size();

        int P[n];
        for(int i=0;i<n;i++)
        P[i]=i;

        function<bool(string,string)>check=[&](string x, string y)->bool{
            int cnt=0;
            for(int i=0;i<p;i++){
                if(x[i]!=y[i])
                cnt++;
            }
            return cnt<=2;
        };

        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(check(S[i],S[j]))
                uni(i,j,P);
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