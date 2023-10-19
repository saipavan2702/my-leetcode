class Solution {
public:
    bool backspaceCompare(string s, string t) {

        function<string(string)>func=[&](string s){
            stack<char>st;
            for(auto &x:s){
                if(x!='#') st.push(x);
                else if(!st.empty()) st.pop();
            }

            string ans="";
            while(!st.empty()){
                ans=st.top()+ans;
                st.pop();
            }

            return ans;
        };

        return func(s)==func(t);
    }
};