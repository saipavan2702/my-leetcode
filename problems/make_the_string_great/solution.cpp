class Solution {
public:
    string makeGood(string s) {
        int n;
        n=s.size();
        if(n<2)
        return s;
        
        stack<char>st;
        for(auto &c:s)
        {
            if(st.empty())
            st.push(c);
            else if(!st.empty() && abs(st.top()-c)== ('a'-'A'))
            st.pop();
            else
            st.push(c);
        }
        string ans="";
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};