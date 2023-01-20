class Solution {
public:
    using P=vector<int>;
    void recur(vector<int>&A,set<P>&ret, P&u, int i){
        int n=A.size();

        if(u.size()>1)
        ret.insert(u);

        if(i==n)
        return;

        if(u.size()==0 || A[i]>=u.back()) {
           u.push_back(A[i]);
           recur(A,ret,u,i+1);
           u.pop_back();
        }

        recur(A,ret,u,i+1);
    }
    vector<vector<int>> findSubsequences(vector<int>& A) {
        set<P>ret;
        P u;
        recur(A,ret,u,0);
        return vector(ret.begin(),ret.end());
    }
};