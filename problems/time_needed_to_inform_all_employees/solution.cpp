class Solution {
public:
    using pI=pair<int,int>;
    int numOfMinutes(int n, int ID, vector<int>& Man, vector<int>& infT) {
        queue<pI>q;
        q.push({ID,infT[ID]});
        
        vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(Man[i]!=-1)
            adj[Man[i]].push_back(i);
        }

        int info=0;

        function<void(int,int)>recur=[&](int x, int curr){
            if(infT[x]==0)
            info=max(info,curr);

            for(auto node:adj[x]){
                recur(node,curr+infT[node]);
            }
        };
        recur(ID,infT[ID]);
        return info;
    }
};