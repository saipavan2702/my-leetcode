class Solution {
public:
    void nextPermutation(vector<int>& A) {
        int x=-1;
        int n=size(A);
        for(int i=n-2;i>=0;i--){
            if(A[i+1]>A[i]){
                x=i;
                break;
            }
        }
        
        for(int i=n-1;i>x && x!=-1;i--){
            if(A[x]<A[i]){
                swap(A[x],A[i]);
                break;
            }
        }
        reverse(begin(A)+x+1,end(A));
    }
};