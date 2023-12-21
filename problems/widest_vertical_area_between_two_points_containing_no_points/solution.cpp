class Solution {
public:
    int maxWidthOfVerticalArea(vector<vector<int>>& P) {
        sort(P.begin(),P.end());
        int ans=0;
        for(int i=1;i<P.size();i++){
            ans=max(ans,P[i][0]-P[i-1][0]);
        }
        return ans;
    }
};


