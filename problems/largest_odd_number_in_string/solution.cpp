class Solution {
public:
    string largestOddNumber(string s) {
        int n=s.size();
        int j=n-1;
        for(int i=n-1;i>=0;i--){
            if((s[i]-'0')%2==0) j--;
            else return s.substr(0,j+1);
        }
        return "";
    }
};