class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>>ans;
        vector<int>have;

        function<void(int,int,int)>recur=[&](int i, int k, int curr){
            if(k==0){
                if(curr==0)ans.push_back(have);
                return;
            }
            if(i>=10 || curr<0)return;
            recur(i+1,k,curr);

            have.push_back(i);
            recur(i+1,k-1,curr-i);
            have.pop_back();
        };
        recur(1,k,n);
        return ans;
    }
};