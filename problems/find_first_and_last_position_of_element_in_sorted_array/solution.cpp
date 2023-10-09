class Solution {
public:
    vector<int> searchRange(vector<int>& A, int target) {
        if(size(A)==0) return vector<int>{-1,-1};

        int hi=upper_bound(A.begin(),A.end(),target)-A.begin();
        int lo=lower_bound(A.begin(),A.end(),target)-A.begin();

        if(lo==size(A) or A[lo]!=target){
            return vector<int>{-1,-1};
        }

        return vector<int>{lo,hi-1};
    }
};