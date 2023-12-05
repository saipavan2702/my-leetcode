class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& P) {
        int n=P.size();
        int cnt=0;

        function<int(int,int,int,int)>recur=[&](int x, int y, int a, int b){
            int dx= abs(a-x);
            int dy = abs(y-b);
            return max(dx, dy);
        };

        for(int i=1;i<n;i++){
            cnt+=recur(P[i-1][0],P[i-1][1],P[i][0],P[i][1]);
        }
        return cnt;
    }
};