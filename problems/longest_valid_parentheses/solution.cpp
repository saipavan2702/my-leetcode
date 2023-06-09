class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        stack<int>st;

        int cn=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(')
            st.push(i);
            else{
                if(!st.empty() && s[st.top()]=='('){
                    st.pop();
                    int prev=-1;
                    
                    if(!st.empty())
                    prev=st.top();

                    cn=max(cn,i-prev);
                }
                else
                st.push(i);
            }
        }
        return cn;
    }
};