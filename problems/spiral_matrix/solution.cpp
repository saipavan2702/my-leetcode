#define pb push_back
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& G) {
        int n=G.size();
        int p=G[0].size();

        int need=n*p;
        vector<int>Q;

        int have=0;
        int sr=0,sc=0;
        int er=n-1,ec=p-1;
        while(have<need){
            for(int i=sc;i<=ec && have<need;i++){
                Q.pb(G[sr][i]);
                have++;
            }
            sr++;

            for(int i=sr;i<=er && have<need;i++){
                Q.pb(G[i][ec]);
                have++;
            }
            ec--;

            for(int i=ec;i>=sc && have<need;i--){
                Q.pb(G[er][i]);
                have++;
            }
            er--;

            for(int i=er;i>=sr && have<need;i--){
                Q.pb(G[i][sc]);
                have++;
            }
            sc++;
        }
        return Q;
    }
};