class Solution {
public:
    int longestOnes(vector<int>& A, int k) {
        int n=A.size();
        int j=0,Q=INT_MIN;
        int v=0;
        for(int i=0;i<n;i++){
            if(A[i]==0)
            v++;
            
            while(v>k){
                if(A[j]==0)
                v--;

                j++;
            }
            Q=max(Q,i-j+1);
        }
        return Q;
    }
};