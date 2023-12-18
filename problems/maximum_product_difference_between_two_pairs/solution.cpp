class Solution {
public:
    int maxProductDifference(vector<int>& A) {
        int n=A.size();
        sort(begin(A),end(A));

        return (A[n-1]*A[n-2])-(A[0]*A[1]);
    }
};