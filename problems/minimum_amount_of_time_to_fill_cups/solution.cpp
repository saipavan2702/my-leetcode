class Solution {
public:
    int fillCups(vector<int>& A) {
        sort(A.begin(),A.end());
        int s=accumulate(A.begin(),A.end(),0);
        int have=ceil(s*1.0/2);
        return max(have,A[2]);
    }
};