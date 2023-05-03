class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& A, vector<int>& B) {
        unordered_set<int>st,du;

        for(auto &x:A)
        st.insert(x);

        for(auto &x:B)
        du.insert(x);

        vector<vector<int>>ans(2);

        for(auto x:st)
        if(du.find(x)==du.end())
        ans[0].push_back(x);

        for(auto x:du)
        if(st.find(x)==st.end())
        ans[1].push_back(x);

        return ans;
    }
};