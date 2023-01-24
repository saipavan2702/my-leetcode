class Solution {
public:
    vector<int>get(int r,int n){
        int x,y;
        x=(r-1)/n;
        y=(r-1)%n;
        x=n-1-x;
        
        if(x%2==n%2)
        y=n-1-y;

        return {x,y};
    }
    int snakesAndLadders(vector<vector<int>>& T) {
        int n=T.size();
        queue<int>q;
        vector<int>dist(n*n+1,-1);
        dist[1]=0;
        q.push(1);

        while(!q.empty()){
            int u=q.front();
            q.pop();
            for(int i=u+1;i<=min(u+6,n*n);i++){
                auto p=get(i,n);
                int v=T[p[0]][p[1]]!=-1?T[p[0]][p[1]]:i;
                if(dist[v]==-1){
                    dist[v]=dist[u]+1;
                    q.push(v);
                }
            }
        }
        return dist[n*n];
    }
};