class Solution {
public:
    char nextGreatestLetter(vector<char>& let, char t) {
        for(int i=0;i<let.size();i++){
            if(let[i]!=t && t<let[i])
            return let[i];
        }

        return let[0];
    }
};