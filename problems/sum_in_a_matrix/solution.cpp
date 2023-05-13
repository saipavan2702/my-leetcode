class Solution {
public:
    int matrixSum(vector<vector<int>>& A) {
        int n=A.size();
        int p=A[0].size();
        
        for(auto&x:A){
            sort(x.begin(),x.end());
        }
        
        int cnt=0;
        for(int i=0;i<p;i++){
            int need=0;
            for(int j=0;j<n;j++){
                need=max(need,A[j][i]);
            }
            cnt+=need;
        }
        return cnt;
    }
};