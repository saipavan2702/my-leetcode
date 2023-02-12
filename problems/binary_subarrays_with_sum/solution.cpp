class Solution {
public:
    int numSubarraysWithSum(vector<int>& A, int g) {
        int n=A.size();

        auto need=[=](int S) {
            if(S<0)
            return 0;
            
            int u=0,curr=0,j=0;

            for(int i=0;i<n;i++) {
            curr+=A[i];
                while(curr>S && j<n){
                    curr-=A[j];
                    j++;
                }
                u+=(i-j+1);
           }
           return u;

        };
        return need(g)-need(g-1);
    }
};