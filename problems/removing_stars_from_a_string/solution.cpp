class Solution {
public:
    string removeStars(string s) {
        stack<char>st;
        for(auto &x:s){
            if(x=='*'){
                if(!st.empty())
                st.pop();
            }
            else
            st.push(x);
        }

        string need="";
        while(!st.empty()){
            need+=st.top();
            st.pop();
        }
        reverse(begin(need),end(need));
        return need;
        
    }
};