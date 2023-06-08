class Solution {
public:
    string robotWithString(string s) {
        stack<char>st;
        string final="";

        vector<int>dict(26,0);
        for(auto &x:s)
        dict[x-'a']++;

        auto lex=[&](){
            for(int i=0;i<26;i++){
                if(dict[i]!=0)return i+'a';
            }
            return 'a'+0;
        };

        for(auto &x:s){
            st.push(x);
            dict[x-'a']--;

            while(!st.empty() && st.top()<=lex()){
                final+=st.top();
                st.pop();
            }
        }

        while(st.size())
        final+=st.top(),st.pop();

        return final;
    }
};