class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(),s.end(),s.begin(),::tolower);
        int l,r=0,n;n=s.size();
        l=n-1;
        while(r<l)
        {
            while(!(isalnum(s[r])) and r<l)
             r++;
            while(!(isalnum(s[l])) and r<l)
             l--;
            if(s[l]!=s[r])
            return 0;
            
            r++;
            l--;
        }
        return 1;
    }
};