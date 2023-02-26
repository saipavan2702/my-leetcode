class Solution {
public:
    vector<int> leftRigthDifference(vector<int>& A) {
        int n=A.size();
        
        vector<int>ret(n);
        vector<int>pref(n,0),suff(n,0);
        
        pref[0]=0;
        for(int i=0;i<n-1;i++){
            pref[i+1]=pref[i]+A[i];
        }
        suff[n-1]=0;
        for(int i=n-1;i>0;i--){
            suff[i-1]=suff[i]+A[i];
        }
        
        for(int i=0;i<n;i++){
            ret[i]=abs(pref[i]-suff[i]);
        }
        return ret;
        
    }
};