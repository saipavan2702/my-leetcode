class Solution {
public:
    vector<int> twoSum(vector<int>& A, int target) {
        int n=size(A);

        unordered_map<int,int>dict;
        int i=0;
        while(i<n){
            if(dict.find((target-A[i]))!=dict.end()){
                return {i,dict[(target-A[i])]};
            }
            dict[A[i]]=i;
            i++;
        }
        return {};
    }
};