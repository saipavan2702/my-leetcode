class Solution {
public:
    vector<int> getAverages(vector<int>& A, int k) {
        int n=A.size();

        vector<int>ans(n,-1);
        if(n<2*k+1)
        return ans;

        long long curr=accumulate(A.begin(),A.begin()+2*k,0LL);
        int j=0;
        
        for(int i=k;i<n;i++){
            if(i<n-k){
                curr+=A[2*k+j];
                ans[i]=curr/(2*k+1);
                curr-=A[j++];
            }
        }
        return ans;
    }
};