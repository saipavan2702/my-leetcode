class Solution {
public:
    string minWindow(string s, string t) {
        int n,p;
        n=s.size();
        p=t.size();
        
        int i=0,j=0,idx=0;
        int len=INT_MAX;
        int dict[128]={0};
        
        for(int i=0;i<p;i++)
        dict[t[i]]++;
        
        while(j<=n and i<n)
        {
            if(p)
            {
                if(j==n)
                break;
                
                dict[s[j]]--;
                if(dict[s[j]]>=0)
                p--;
                
                j++;
            }
            else
            {
                if(j-i<len)
                len=j-i,idx=i;
                
                dict[s[i]]++;
                if(dict[s[i]]>0)
                p++;
                
                i++;
            }
        }
        if(len==INT_MAX)
        return "";
        
        return s.substr(idx,len);
    }
};