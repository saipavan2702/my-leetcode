class Solution {
public:
    int greed(string&s,char a,char b)
    {
        int n,cnt=0;
        n=s.size();
        string str="";
        for(int i=0;i<n;i++)
        {
            if(s[i]==b and str.size()!=0 and str.back()==a)
            {str.pop_back();
             cnt++;}
            else
            str.push_back(s[i]);
        }
        s=str;
        return cnt;
    }
    int maximumGain(string s, int x, int y) {
        int xa=0,xb=0;
        if(x>y)
        {
            xa=greed(s,'a','b');
            xb=greed(s,'b','a');
        }
        else
        {
            xb=greed(s,'b','a');
            xa=greed(s,'a','b');
        }
        return xa*x+xb*y;
    }
};