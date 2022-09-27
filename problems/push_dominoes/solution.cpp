class Solution {
public:
    string pushDominoes(string d) {
        int n;
        n=d.size();
        
        int i=0,j=0;
        string ans="";
        for(i=0;i<n;i++)
        {
            if(d[i]=='.')
            continue;
            else if(d[i]==d[j] or d[i]=='L' and d[j]=='.')
            {
                for(int r=j;r<i;r++)
                d[r]=d[i];
            }
            else if(d[j]=='R' and d[i]=='L')
            {
                int mid=(i-j-1)/2;
                for(int r=1;r<=mid;r++)
                {
                    d[i-r]='L';
                    d[j+r]='R';
                }
            }
            j=i;
        }
        if(d[j]=='R')
        {
            for(int r=j;r<n;r++)
            d[r]='R';
        }
        return d;   
    }
};