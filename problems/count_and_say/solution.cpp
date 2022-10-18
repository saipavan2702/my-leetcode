class Solution {
public:
    string countAndSay(int n) {
        string ans="1";
        if(n==1)
        return ans;
        
        while(n>1)
        {
            int p,cnt=1;
            ans+='#';
            p=ans.size();
            string res="";
            for(int i=1;i<p;i++)
            {
                if(ans[i]!=ans[i-1])
                {
                    res+=to_string(cnt)+ans[i-1];
                    cnt=1;
                }
                else cnt++;
            }
            ans=res;
            n--;
        }
        return ans;
    }
};