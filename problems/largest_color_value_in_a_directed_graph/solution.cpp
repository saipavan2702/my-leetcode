class Solution {
public:
    int largestPathValue(string s, vector<vector<int>>& E) {
        int V=s.size();

        vector<int>adj[V+1];
        for(auto e:E){
            adj[e[0]].push_back(e[1]);
        }

        vector<int>indeg(V,0);
        for(int i=0;i<V;i++){
            for(auto u:adj[i]){
                indeg[u]++;
            }
        }

        queue<int>q;
        for(int i=0;i<V;i++){
            if(indeg[i]==0)
            q.push(i);
        }


        vector<vector<int>>dict(V,vector<int>(26,0));
        for(int i=0;i<V;i++){
            dict[i][s[i]-'a']++;
        }

        int vis=0,ass=0;
        while(!q.empty()){
            int x=q.front();
            q.pop();
            vis++;
            for(auto u:adj[x]){
                indeg[u]--;
                for(int i=0;i<26;i++){
                    dict[u][i]=max(dict[u][i], dict[x][i]+(s[u]-'a'==i?1:0));
                }
                if(indeg[u]==0)
                q.push(u);
            }
            ass=max(ass,*max_element(dict[x].begin(),dict[x].end()));
        }

        return vis==V?ass:-1;       
    }
};