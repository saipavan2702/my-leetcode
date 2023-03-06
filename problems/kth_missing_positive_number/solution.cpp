class Solution {
public:
    int findKthPositive(vector<int>& A, int k) {
        int n=size(A);
        int lo(0),hi(n);

        while(lo<hi){
            int u=(lo+hi)/2;
            if(A[u]-(u+1)<k)
            lo=u+1;
            else
            hi=u;
        }
        return lo+k;
    }
};