class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<unordered_set<int>>indeg(n);
        for(auto &x:roads){
            indeg[x[0]].insert(x[1]);
            indeg[x[1]].insert(x[0]);
        }

        int hi=0;
        for(int i=0;i<n;i++){
            for(int x=i+1;x<n;x++){
                int need= indeg[i].size() + indeg[x].size();
                if (indeg[x].count(i)) need--;
                
                hi=max(hi,need);
            }
        }
        return hi;
    }
};