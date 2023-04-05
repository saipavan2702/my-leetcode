class Solution {
public:
    int minimizeArrayValue(vector<int>& A) {
        int n=size(A);
        auto need=0;
        int Q=*max_element(begin(A),end(A));

        auto test=[&](int u){
            long long curr=0;
            for(int i=0;i<n;i++){
                curr+=A[i];
                if(curr>(long long)u*(i+1))
                return 0;
            }
            return 1;
        };

        int lo(0),hi(Q);
        while(lo<hi){
            int u=(lo+hi)/2;
            if(test(u))
            hi=u;
            else
            lo=u+1;
        }
        return hi;
    }
};