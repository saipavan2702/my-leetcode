class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& G) {
        int n=G.size();
        int cn=0;
        sort(begin(G),end(G),[](vector<int>& a, vector<int>& b){
            return a[1]<b[1];
        });

        auto pre=G[0];
        for(auto&x:G){
            if(pre[1]>x[0]){
                cn++;
            }else
            pre=x;
        }
        return cn-1;
    }
};