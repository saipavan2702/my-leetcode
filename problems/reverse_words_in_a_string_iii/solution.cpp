class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string sing;

        string ans="";
        while(ss >> sing){
            reverse(sing.begin(),sing.end());
            ans+=sing;
            ans+=" ";
        }
        ans.pop_back();
        return ans;
    }
};