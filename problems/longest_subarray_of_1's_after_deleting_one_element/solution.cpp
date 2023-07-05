class Solution {
public:
    int longestSubarray(vector<int>& A) {
        int s=accumulate(A.begin(),A.end(),0);
        int j=0,n=A.size();
        if(s==n)return n-1;

        int z=0,h=0;
        for(int i=0;i<n;i++){
            if(A[i]==0)z++;
            while(z>1){
                if(A[j]==0)
                z--;

                j++;
            }
            h=max(h,i-j);
        }
        return h;
    }
};