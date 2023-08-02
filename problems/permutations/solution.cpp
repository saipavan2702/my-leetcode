class Solution {
public:
    vector<vector<int>> permute(vector<int>& A) {
        int n=A.size();
        vector<vector<int>>ans;

        function<void(int)>recur=[&](int x){
            if(x==n-1){
                ans.push_back(A);
                return;
            }
            for(int i=x;i<n;i++){
                swap(A[x],A[i]);
                recur(x+1);
                swap(A[x],A[i]);
            }
        };
        recur(0);
        return ans;
    }
};