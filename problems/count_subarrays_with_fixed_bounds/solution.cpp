class Solution {
public:
    long long countSubarrays(vector<int>& A, int lK, int hK) {
        long long ans=0;
        int n=size(A);

        int pl=-1,ph=-1;
        int re=-1;
        for(int i=0;i<n;i++) {
            if(A[i]<lK || A[i]>hK)
            re=i;

            if(A[i]==lK)
            pl=i;

            if(A[i]==hK)
            ph=i;

            ans+=max(0,min(pl,ph)-re);
        }
        return ans;
    }
};