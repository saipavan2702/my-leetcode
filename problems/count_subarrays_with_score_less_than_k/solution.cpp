class Solution {
public:
    long long countSubarrays(vector<int>& A, long long k) {
        int n=A.size();

        long long h=0;
        long long curr=0;
        int i=0,j=0;
        
        for(int i=0;i<n;i++){
            curr+=A[i];
            
            while(curr*(i-j+1)>=k){
                curr-=A[j++];
            }
            int len=(i-j+1);
            h+=len;
        }
        return h;
    }
};