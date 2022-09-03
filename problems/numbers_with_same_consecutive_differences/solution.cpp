class Solution {
public:
    vector<int>ans;
    void recur(int n,int k,string s)
    {
        if(n==0)
        {
            ans.push_back(stoi(s));
            return;
        }
        for(char ch='0';ch<='9';ch++)
        {
            if(s.size()==0 and ch=='0')
            continue;
            
            if(s.size()==0)
            {
             s.push_back(ch);               
             recur(n-1,k,s);
             s.pop_back();
            }
            else
            {
              char r=s.back();
              if(abs(r-ch)==k)
              {
               s.push_back(ch);
               recur(n-1,k,s);
               s.pop_back();
              } 
            }
        }
    }
    vector<int> numsSameConsecDiff(int n, int k) {
        ans.clear();
        recur(n,k,"");
        return ans;
    }
};