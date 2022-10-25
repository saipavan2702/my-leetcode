class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string ret="";
        string st="";
        for(auto&x:word1)
            ret+=x;
        
        for(auto&x:word2)
            st+=x;
        
        return ret==st;
    }
};