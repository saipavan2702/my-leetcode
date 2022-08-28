class Solution {
public:
    string largestPalindromic(string num) {
        int dict[10]={0};
        for(auto ch:num)
        dict[ch-'0']++;
        
        string ans="";
        for(int i=9;i>=0;i--)
        {
            if(ans.size()==0 and i==0)
            continue;
            
            while(dict[i]>1)
            {
                ans+='0'+i;
                dict[i]-=2;
            }
        }
        string str=ans;
        for(int i=9;i>=0;i--)
        {
            if(dict[i]>0)
            {
                ans+='0'+i;
                break;
            }
        }
        reverse(str.begin(),str.end());
        ans=ans+str;
        return ans;
        
    }
};