class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& T) {
        int n;
        n=T.size();

        sort(T.begin(),T.end());
        int ret=T[0][1];
        int cnt=1;
        for(auto x:T) {
           if(x[0]>ret) {
               cnt++;
               ret=x[1];
           }
           else
           ret=min(ret,x[1]);
        }
        return cnt;
    }
};