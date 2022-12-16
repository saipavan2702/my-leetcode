class Solution {
public:
    int calculate(string s) {
        int n;
        n=s.size();

        stack<pair<int,int>>st;
        int ans=0,sgn=1;
        
        for(int i=0;i<n;i++)
        {
            auto c=s[i];
            if(isdigit(c))
            {
               long long int ret=0;
               while(i<n and isdigit(s[i]))
               {
                  ret=ret*10+s[i]-'0';
                  i++;
               }
               i--;
               ans+=(ret*sgn);
               sgn=1;
            }
            else if(c=='(')
            {
              st.push({ans,sgn});
              ans=0;
              sgn=1;
            }
            else if(c==')')
            {
                ans=st.top().first+(st.top().second*ans);
                st.pop();
            }
            else if(c=='-')
            sgn=-1*sgn;
        }
        return ans;
    }
};