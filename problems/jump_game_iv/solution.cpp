class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n=arr.size();
        queue<int>q;
        using uv=unordered_map<int,vector<int>>;
        uv dict;

        for(int i=0;i<n;i++){
            dict[arr[i]].push_back(i);
        }
        q.push(0);
        vector<bool>vis(n,0);

        int cnt=0;
        vis[0]=1;
        while(!q.empty()){
            int sz=q.size();
            while(sz--){
                auto x=q.front();
                q.pop();

                if(x==n-1)return cnt;
                if(x+1<n && !vis[x+1]){
                    vis[x+1]=1;
                    q.push(x+1);
                }
                if(x-1>=0 and !vis[x-1]){
                    vis[x-1]=1;
                    q.push(x-1);
                }
                for(auto u:dict[arr[x]]){
                    if(vis[u])continue;
                    vis[u]=1;
                    q.push(u);
                }
                dict[arr[x]].clear();
            }
            cnt++;
        }
        return -1;
    }
};