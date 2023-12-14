class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& G) {
        int n=G.size(),p=G[0].size();
        vector<int>R(n);
        vector<int>C(p);

        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                if(G[i][j]) R[i]++,C[j]++;
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
                G[i][j]=R[i]+C[j]-(n-R[i])-(p-C[j]);
            }
        }
        return G;
    }
};