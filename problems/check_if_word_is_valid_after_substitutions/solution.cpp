class Solution {
public:
    bool isValid(string s) {
        vector<char>st;
        for(auto&x:s)
        {
            if(x=='c' and st.size()>1 and st.back()=='b' and st[st.size()-2]=='a')
            st.resize(st.size()-2);
            else
            st.push_back(x);
        }
        return st.empty();
    }
};