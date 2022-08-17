class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> ref = {".-","-...","-.-.","-..",".","..-.","--.","....",
                  "..",".---","-.-",".-..","--","-.","---",".--.",
                  "--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        unordered_set<string>st;
        for(auto &x:words)
        {
            string s="";
            for(auto&y:x)
            {
                s+=ref[y-'a'];
            }
            st.insert(s);
        }
        return st.size();
    }
};