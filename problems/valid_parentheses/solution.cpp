class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(auto &x:s){
            if(st.empty())
            st.push(x);
            else if(x=='}' and st.top()=='{' || x==')' and st.top()=='(' || x==']' and st.top()=='[')
            st.pop();
            else
            st.push(x);
        }
        return st.empty();
    }
};