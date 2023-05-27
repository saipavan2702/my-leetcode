class Solution {
public:
    using vi=vector<int>;
    vi edgeCount;
    vi nodeCount;

    void uni(int u, int v, int P[]){
        int a=find(u,P);
        int b=find(v,P);

        if(a!=b){
            P[a]=b;
            nodeCount[b]+=nodeCount[a];
            edgeCount[b]+=edgeCount[a]+1;

        }else edgeCount[a]++;
    }
    int find(int r, int P[]){
        if(P[r]==r)
        return r;

        return P[r]=find(P[r],P);
    }
    int countCompleteComponents(int n, vector<vector<int>>& E) {
        int P[n];
        for(int i=0;i<n;i++)P[i]=i;

        edgeCount.resize(n,0);
        nodeCount.resize(n,1);
        
        for(auto x:E){
            uni(x[0],x[1],P);
        }

        int have=0;
        for(int i=0;i<n;i++){
            if(P[i]==i){
                int n=nodeCount[i];
                int need=edgeCount[i];

                if((n*(n-1))/2==need)
                have++;
            }
        }
        return have;
        
    }
};