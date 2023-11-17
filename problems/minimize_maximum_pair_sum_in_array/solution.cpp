class Solution {
public:
    int minPairSum(vector<int>& A) {
        sort(begin(A),end(A));
        int hi=0;

         int i = 0;
        int j =A.size() - 1;
        while(i < j){
            hi = max(hi, (A[i++] + A[j--]));
        }
        return hi;
    }
};
