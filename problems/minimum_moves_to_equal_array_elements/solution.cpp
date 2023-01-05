class Solution {
public:
    int minMoves(vector<int>& A) {
        int s=accumulate(A.begin(),A.end(),0);
        int n=A.size();
        int l=*min_element(A.begin(),A.end());

        return s-n*l;
    }
};