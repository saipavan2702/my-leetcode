class Solution {
public:
    int search(vector<int>& A, int t) {
        int n=size(A);

        int lo(0),hi(n-1);
        while(lo<=hi){
            int u=(lo+hi)/2;

            if(A[u]==t)
            return u;
            else if(A[u]>t)
            hi=u-1;
            else
            lo=u+1;
        }
        return -1;
    }
};