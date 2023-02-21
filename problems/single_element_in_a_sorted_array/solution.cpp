class Solution {
public:
    int singleNonDuplicate(vector<int>& A) {
        int n=A.size();

        int lo(0),hi(n-1),ans=-1;

        while(lo<hi) {
            int u=(lo+hi)/2;
            if(!(u&1) && A[u]==A[u+1] || (u&1) && A[u]==A[u-1])
            lo=u+1;
            else 
            hi=u;
        }
        return A[lo];
    }
};