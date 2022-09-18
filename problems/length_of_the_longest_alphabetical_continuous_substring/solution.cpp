class Solution {
public:
    int longestContinuousSubstring(string s) {
        int i=1,cnt=1,res=0;
        int n;
        n=s.size();
        while(i<n)
        {
            int x,y;
            x=s[i]-'a';
            y=s[i-1]-'a';
            if(x-y==1)
            cnt++;
            else
            cnt=1;
            
            res=max(res,cnt);  
            i++;
        }
        res=max(res,cnt);
        return res;
    }
};