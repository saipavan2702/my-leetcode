class Solution {
public:
    int countCollisions(string dir) {
        int n=dir.size();
        int cn=0;

        stack<char>st;
        for(int i=0;i<n;i++){
            if(st.empty())
            st.push(dir[i]);
            else if(st.top()=='R' && dir[i]=='L'){
               st.pop();
               dir[i]='S';
               i--;
               cn+=2;
            }else if(st.top()=='R' && dir[i]=='S'){
                st.pop();
                i--;
                cn++;
            }else if(st.top()=='S' && dir[i]=='L')
            cn++;
            else
            st.push(dir[i]);
        }
        return cn;
    }
};