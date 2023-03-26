class Solution {
public:
    int find(int r, int P[]){
        if(r==P[r])
        return r;

        return P[r]=find(P[r],P);
    }
    int need(int i, vector<int>& E){
        int st=i,en=E[i];
        int k=1;
        while(st!=en){
            en=E[en];
            k++;
        }
        return k;
    }
    int longestCycle(vector<int>& E) {
        int n=E.size();
        int P[n+1];

        for(int i=0;i<n;i++)
        P[i]=i;


        int ass=-1;
        for(int i=0;i<n;i++){
            if(E[i]==-1)
            continue;

            int a=find(i,P);
            int b=find(E[i],P);

            if(a!=b)
            P[a]=b;
            else
            ass=max(ass, need(i,E));
        }
        return ass;
    }
};