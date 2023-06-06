class Solution {
public:
    bool canMakeArithmeticProgression(vector<int>& A) {
        int n=size(A);
        sort(A.begin(),A.end());

        for(int i=1;i<n-1;i++){
            if(A[i]-A[i-1]!=A[i+1]-A[i])
            return 0;
        }
        return 1;
    }
};