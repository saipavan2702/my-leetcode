class Solution {
public:
    vector<vector<int>> differenceOfDistinctValues(vector<vector<int>>& G) {
        int n=G.size();
        int p=G[0].size();
        
        vector<vector<int>>ans(n,vector<int>(p));
        
        
        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                set<int>pref,suff;
                int u=i-1,v=j-1;
                while(u>=0 && v>=0){
                    pref.insert(G[u--][v--]);
                }
                u=i+1,v=j+1;
                while(u<n && v<p){
                    suff.insert(G[u++][v++]);
                }
                int cnt=suff.size()-pref.size();
                ans[i][j]=abs(cnt);
            }
        }
        return ans;
    }
};