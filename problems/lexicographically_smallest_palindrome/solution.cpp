class Solution {
public:
    string makeSmallestPalindrome(string s) {
        int n=s.size();
        for(int i=0;i<n/2;i++){
            if(s[i]!=s[n-i-1]){
                if(s[i]-'a'>s[n-i-1]-'a'){
                    s[i]=s[n-i-1];
                }else{
                    s[n-i-1]=s[i];
                }
            }
        }
        return s;
    }
};