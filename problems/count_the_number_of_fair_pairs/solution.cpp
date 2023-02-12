class Solution {
public:
    long long countFairPairs(vector<int>& A, int lo, int hi) {
        int n=A.size();
        long long u=0;

        sort(A.begin(),A.end());
        for(int i=0;i<n;i++) {
            auto Q=upper_bound(A.begin()+i+1,A.end(),hi-A[i])-A.begin();
            auto E=lower_bound(A.begin()+i+1,A.end(),lo-A[i])-A.begin();
            u+=(Q-E);
        }
        return u;
    }
};