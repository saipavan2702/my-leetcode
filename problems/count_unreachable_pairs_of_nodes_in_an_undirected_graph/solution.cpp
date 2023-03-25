class Solution {
public:
    int find(int r, int P[]){
        if(r==P[r])
        return r;

        return P[r]=find(P[r],P);
    }
    void uni(int u, int v, int P[]){
        if(u!=v)
        P[v]=u;
    }
    long long countPairs(int N, vector<vector<int>>& E) {
        vector<int>adj[N+1];
        int P[N+1];
        for(int i=0;i<N;i++)
        P[i]=i;

        for(auto e:E){
            int a=find(e[0],P);
            int b=find(e[1],P);
            uni(a,b,P);
        }

        unordered_map<int,int>freq;
        for(int i=0;i<N;i++){
           freq[find(P[i],P)]++;
        }

        long long ans=0;
        for(auto [x,y]:freq){
           ans+=(long long)(y)*(N-y);
           N-=y;
        }
        return ans;

    }
};