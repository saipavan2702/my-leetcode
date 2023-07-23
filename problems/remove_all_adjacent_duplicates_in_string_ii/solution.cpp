class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<char,int>>st;
        int n=s.size();
        for(int i=0;i<n;i++){
            if(st.empty()){
                st.push({s[i],1});
            }else{
                if(st.top().first==s[i]){
                    if(st.top().second+1==k) st.pop();
                    else{
                        int f=st.top().second;
                        st.pop();
                        st.push({s[i],f+1});
                    }
                }else{
                    st.push({s[i],1});
                }
            }
        }
        string ans="";
        while(!st.empty()){
            ans=string(st.top().second,st.top().first)+ans;
            st.pop();
        }
        return ans;
    }
};