class Solution {
public:
    int isWinner(vector<int>& A, vector<int>& B) {
        int n=A.size();
        int curr=0;
        
        int h=0;
        for(int i=0;i<n;i++){
            if(h)
                curr+=2*A[i],h--;
            else
                curr+=A[i];

            if(A[i]==10 )
                h=2;
            
        }
        
        h=0;
        int res=0;
        for(int i=0;i<n;i++){
            if(h)
                res+=2*B[i],h--;
            else
                res+=B[i];

            if(B[i]==10)
                h=2;
        }
        
        if(curr<res)
            return 2;
        else if(curr>res)
            return 1;
        
        return 0;
        
        
    }
};