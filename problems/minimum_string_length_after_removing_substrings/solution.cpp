class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        int n=s.size();
        
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push(s[i]);
            }else if(s[i]=='B' || s[i]=='D'){
                if(s[i]=='B'){
                    if(st.top()=='A'){
                        st.pop();
                    }else{
                    st.push(s[i]);
                    }
                }else if(s[i]=='D'){
                    if(st.top()=='C'){
                        st.pop();
                    }else{
                    st.push(s[i]);
                    }
                }
            }else{
                st.push(s[i]);
            }
        }
        
        int cnt=0;
        while(!st.empty()){
            st.pop();
            cnt++;
        }
        return cnt;
        
    }
};