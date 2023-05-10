class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int sr=0,sc=0;
        int er=n-1,ec=n-1;

        vector<vector<int>>ans(n,vector<int>(n));
        int h=1;

        while(h<=n*n) {

            for(int i=sc;i<=ec;i++) {
            ans[sr][i]=h;
            h++;
            }
            sr++;

            for(int i=sr;i<=er;i++) {
                ans[i][ec]=h;
                h++;
            }
            ec--;

            for(int i=ec;i>=sc;i--) {
                ans[er][i]=h;
                h++;
            }
            er--;

            for(int i=er;i>=sr;i--) {
                ans[i][sc]=h;
                h++;
            }
            sc++;
        }
        return ans;
    }
};