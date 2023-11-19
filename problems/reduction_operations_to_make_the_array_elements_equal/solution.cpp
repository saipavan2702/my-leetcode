class Solution {
public:
    int reductionOperations(vector<int>& A) {
        int n=A.size();
        sort(begin(A),end(A));

        int ans=0,have=0;
        for(int i=1;i<n;i++){
            if(A[i]!=A[i-1]) have++;
            ans+=have;
        }
        return ans;
    }
};