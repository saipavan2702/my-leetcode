class Solution {
public:
    bool isBipartite(vector<vector<int>>& T) {
        int n;
        n=T.size();

        vector<int>vis(n,0);
        queue<int>q;

        for(int i=0;i<n;i++){
           if(!vis[i]){
               q.push(i);
               vis[i]=1;
               while(!q.empty())
               {
                   int x=q.front();
                   q.pop();
                   for(auto u:T[x])
                   {
                       if(vis[u]==vis[x])
                       return 0;
                       
                       if(!vis[u])
                       vis[u]=-vis[x],q.push(u);
                   }
               }
           }
        }
        return 1;

        // function<bool(int,int)>recur=[&](int ch, int col){
        //     if(vis[ch]!=0)
        //     return (vis[ch]==col);

        //     vis[ch]=col;
        //     for(auto x:T[ch]){
        //         if(vis[x]==vis[ch])
        //         return false;

        //         if(!vis[x]){
        //             vis[x]=-col;
        //             recur(x,vis[x]);
        //         }
        //     }
        //     return true;
        // };
        // return recur(0,1);
    }
};