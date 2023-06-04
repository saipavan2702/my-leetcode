class Solution {
public:
    int semiOrderedPermutation(vector<int>& A) {
        int n=A.size();
        int is=-1;
        int ib=-1;
        
        if(A[0]==1 && A[n-1]==n)
            return 0;
        
        for(int i=0;i<n;i++){
            if(A[i]==1)
                is=i;
            if(A[i]==n)
                ib=i;
        }
        
        if(is>ib){
            return abs(is-0)+abs(ib-(n-1))-1;
        }else
            return abs(is-0)+abs(ib-(n-1));
    }
};