class Solution {
public:
    int findValueOfPartition(vector<int>& A) {
        sort(A.begin(),A.end());
        int ans=1e9;
        for(int i=1;i<A.size();i++){
            ans=min(ans,A[i]-A[i-1]);
        }
        return ans;
    }
};