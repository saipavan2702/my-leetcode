class Solution {
public:
    vector<int> distinctDifferenceArray(vector<int>& A) {
        int n=A.size();
        unordered_set<int>st;
        
        vector<int>pref(n+1),suff(n+1);
        for(int i=0;i<n;i++){
            st.insert(A[i]);
            pref[i]=st.size();
        }
        
        st.clear();
        for(int i=n-1;i>=0;i--){
            st.insert(A[i]);
            suff[i]=st.size();
        }
        suff[n]=0;
        
        vector<int>ans(n);
        for(int i=0;i<n;i++){
            ans[i]=pref[i]-suff[i+1];
        }
        
        return ans;
    }
};