class Solution {
public:
    vector<long long> findPrefixScore(vector<int>& A) {
        int n=A.size();
        vector<int>pref(n);
        int hi=0;
        
        vector<long long>need;
        
        for(int i=0;i<n;i++){
            hi=max(hi,A[i]);
            pref[i]=A[i]+hi;
            need.push_back(pref[i]);
        }
        for(int i=1;i<n;i++){
            need[i]+=need[i-1];
        }
    
        return need;
    }
};