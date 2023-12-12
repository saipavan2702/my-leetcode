class Solution {
public:
    int maxProduct(vector<int>& A) {
        sort(rbegin(A),rend(A));
        return (A[0]-1)*(A[1]-1);
    }
};