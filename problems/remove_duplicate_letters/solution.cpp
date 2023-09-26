class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n=s.size();
        vector<int>dict(26,0);
        unordered_set<char>st;

        for(auto &x:s)dict[x-'a']++;

        string res;
        for(int i=0;i<n;i++){
            dict[s[i]-'a']--;
            if(st.find(s[i])==st.end()){
                while(!res.empty() and res.back()>s[i] and dict[res.back()-'a']>0)
                st.erase(res.back()),res.pop_back();

                res.push_back(s[i]);
                st.insert(s[i]);
            }
        }
        return res;
    }
};