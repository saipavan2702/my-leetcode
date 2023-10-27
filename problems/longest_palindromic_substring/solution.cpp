class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        int len=0;
        string ans="";

        for(int i=0;i<n;i++){
            int x=i,y=i;
            while(x>=0 and y<n and s[x]==s[y]){
                x--;
                y++;
            }

            if(y-x-1>len){
                len=y-x-1;
                ans=s.substr(x+1,len);
            }

            x=i;y=i+1;
            while(x>=0 and y<n and s[x]==s[y]){
                x--;
                y++;
            }

            if(y-x-1>len){
                len=y-x-1;
                ans=s.substr(x+1,len);
            }
        }
        return ans;
    }
};