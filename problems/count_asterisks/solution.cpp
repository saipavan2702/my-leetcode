class Solution {
public:
    int countAsterisks(string s) {
        int i,n,res=0;
        n=s.size();
        if(n==0)
        return 0;
        
        map<char,int>freq;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='|' and res<2)
            {
                res++;
            }
            else if(s[i]!='|' and res%2==0)
            {
                res=0;
                while(s[i]!='|')
                {
                   if(i==n)
                   return freq['*'];
                   else if(s[i]=='*')
                    freq[s[i]]++;
                    i++;
                }
                i--;
            }
            else if(s[i]=='|' and res>=2)
                res++;
            
        }
        return freq['*'];
    }
};