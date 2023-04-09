class Solution {
public:
    int diagonalPrime(vector<vector<int>>& A) {
        int n=A.size();
        auto check=[&](int u){
            if(u<=1)
                return 0;
            
            for(int i=2;i*i<=u;i++){
                if(u%i==0)
                    return 0;
            }
            
            return 1;
        };
        
        int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j || i==n-j-1){
                    cnt=max(cnt,check(A[i][j])?A[i][j]:0);
                }
            }
        }
        return cnt;
        
    }
};