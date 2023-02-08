class Solution {
public:
    int minSubArrayLen(int t, vector<int>& A) {
        int len=INT_MAX;
        int i=0,j=0,n=A.size();
        int curr=0;
        while(i<n){
            curr+=A[i];
            while(curr>=t){
                len=min(len,i-j+1);
                curr-=A[j];
                j++;
            }
            i++;
        }
        return len==INT_MAX?0:len;
    }
};