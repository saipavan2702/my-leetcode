class Solution {
public:
    int buyChoco(vector<int>& A, int M) {
        int n=size(A);
        
        sort(A.begin(),A.end());
        
        auto it=lower_bound(A.begin(),A.end(),M)-A.begin();
        if(it>=2){
            if(A[0]+A[1]<=M)
            return M-(A[0]+A[1]);
        }
        
        return M;
    }
};