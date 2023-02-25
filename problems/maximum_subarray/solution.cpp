class Solution {
public:
    int maxSubArray(vector<int>& A) {
        int n=size(A);

        int curr(0),global(-1e9);
        for(int i=0;i<n;i++){
            curr+=A[i];
            curr=max(A[i],curr);
            global=max(global,curr);
        }
        return global;

    }
};