class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
        int n=A.size();
        int lo(0),hi(n-1);

        while(lo<=hi){
            int u=(lo+hi)/2;
            if(A[u]>A[u+1]) hi=u-1;
            else lo=u+1;
        }
        return lo;
    }
};