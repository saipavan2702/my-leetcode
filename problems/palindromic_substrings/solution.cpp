class Solution {
public:
    int countSubstrings(string s) {
         int cnt=0,n,x,y;
    n=s.size();
    for(int i=0;i<n;i++)
    {
      
      x=i;
      y=i;
      while(x>=0 and y<n and s[x]==s[y])
      {
        cnt++;
        x--;
        y++;
      }

      x=i;
      y=i+1;
      while(x>=0 and y<n and s[x]==s[y])
      {
        cnt++;
        x--;
        y++;
      }
    }
    return cnt;
    }
};