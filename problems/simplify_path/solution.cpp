class Solution {
public:
    string simplifyPath(string p) {
        int n=p.size();
        stack<string>st;
        for(int i=0;i<n;i++) {

            if(p[i]=='/')
            continue;

            string Q="";
            while(i<n && p[i]!='/'){
                Q+=p[i];
                i++;
            }
            if(Q==".")
            continue;
            else if(Q=="..") {

                if(!st.empty())
                st.pop();
            }
            else
            st.push(Q);
        }
        string u="";
        while(!st.empty())
        u="/"+st.top()+u,st.pop();

        return u==""?"/":u;
    }
};