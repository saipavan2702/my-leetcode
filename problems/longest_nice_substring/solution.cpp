class Solution {
public:
    string longestNiceSubstring(string s) {
        string ans="";
        int mx=INT_MIN;
        for(int i=0;i<s.size();i++)
        {
            bool up[26]={};
            bool lo[26]={};
            int res=0;
         for(int j=i;j<s.size();j++)
         {
             if(islower(s[j]))
             lo[s[j]-'a']=1;
             else
             up[s[j]-'A']=1;
             
             res=j-i+1;
             if(res>mx)
             {
                 int k;
                 for(k=0;k<26;k++)
                 {
                     if((lo[k])!=(up[k]))
                     break;
                 }
                 if(k==26)
                 {
                     mx=res;
                     ans=s.substr(i,mx);
                 }
             }
         }
        }
        return ans;
           
        
        
    }
};