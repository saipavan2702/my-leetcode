class Solution {
public:
    int maxJump(vector<int>& st) {
        int n;
        n=st.size();
        int res=st[1]-st[0];
        
        for (int i=1; i<n-1;i++)
        res=max(res,st[i+1]-st[i-1]);
       
        return res;
    }
};