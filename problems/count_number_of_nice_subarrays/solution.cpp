class Solution {
public:
    int numberOfSubarrays(vector<int>& A, int k) {
        int need=0,cnt(0);
        int n=size(A);

        int h(0);
        int j=0;
        for(int i=0;i<n;i++) {

            if(A[i]&1)
            need++,cnt=0;

            while(need==k){
                cnt++;
                if(A[j]&1)
                need--;

                j++;
            }
            h+=cnt;
        }
        return h;
    }
};