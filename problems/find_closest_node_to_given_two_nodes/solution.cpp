class Solution {
public:
    void recur(vector<int>& E, int r, vector<int>&nu){
        queue<int>q;
        q.push(r);
        while(!q.empty()){
            int u=q.front();
            q.pop();
            if(E[u]!=-1){
                if(nu[E[u]]==-1){
                    nu[E[u]]=nu[u]+1;
                    q.push(E[u]);
                }
            }
        }
    }
    int closestMeetingNode(vector<int>& E, int x, int y) {
        int n=E.size();
        vector<int>nx(n,-1),ny(n,-1);
        nx[x]=0;
        ny[y]=0;
        recur(E,x,nx);
        recur(E,y,ny);

        int d=INT_MAX;
        int ni=-1;
        for(int i=0;i<n;i++){
            if(nx[i]!=-1 && ny[i]!=-1){
                if(d>max(nx[i],ny[i])){
                    d=max(nx[i],ny[i]);
                    ni=i;
                }
            }
        }
        return ni;
    }
};