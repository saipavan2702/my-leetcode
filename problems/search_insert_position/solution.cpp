class Solution {
public:
    int searchInsert(vector<int>& A, int T) {
        int n=A.size();
        int lo(0),hi(n-1);

        while(lo<=hi){
            int u=(lo+hi)/2;
            if(A[u]==T)
            return u;
            else if(A[u]>T)
            hi=u-1;
            else
            lo=u+1;
        }
        return lo;
    }
};