class Solution {
public:
    int maxScore(vector<int>&A) {
        int n=size(A);
        
        // int pos=0,neg=0;
        // for(int i:A){
        //     if(i<0)
        //         neg++;
        //     else
        //         pos++;
        // }
        
        sort(rbegin(A),rend(A));
        int cnt=0;
        
        vector<int>pref(n);
        long long curr=0;
        for(int i=0;i<n;i++){
            curr+=A[i];
            if(curr>0)
                cnt++;
            if(curr<0)
                break;
        }
        
    
        return cnt;
    }
};