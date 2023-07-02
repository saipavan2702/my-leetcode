class Solution {
public:
    int longestAlternatingSubarray(vector<int>& A, int th) {
        int n=A.size();
        if(n==1)
            return A[0]%2==0 && A[0]<=th;
        
        int hi=0;
        for(int i=0;i<n;i++){
            if(A[i]%2==0 && A[i]<=th){
                int len=1;
                for(int j=i;j+1<n;j++){
                    if(A[j]%2!=A[j+1]%2 && A[j]<=th and A[j+1]<=th){
                        len++;
                    }else{
                        hi=max(hi,len);
                        break;
                    }
                }
                hi=max(hi,len);
            }
            
        }
         
        return hi;
    }
};