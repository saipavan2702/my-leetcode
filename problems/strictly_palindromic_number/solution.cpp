class Solution {
public:
    bool check(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]!=s[s.size()-i-1]);
            return 0;
        }
        return 1;
    }
    string tobinary(int n,int i)
    {
        int ans=0;
        while(n!=0)
        {
            ans+=(n%i);
            n/=i;
        }
        return to_string(ans);
    }
    bool isStrictlyPalindromic(int n) {
        vector<string>res;
        for(int i=2;i<=n-2;i++)
        {
            string bin=tobinary(n,i);
            res.push_back(bin);
        }
        for(auto&x:res)
        {
            if(!check(x))
            return 0;
        }
        return 1;
    }
};