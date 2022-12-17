class Solution {
public:
    int evalRPN(vector<string>&s) {
        stack<long long>st;
        for(auto&c:s)
        {
           if(c=="/" or c=="+" or c=="-" or c=="*")
           {
              long long a=st.top();st.pop();
              long long b=st.top();st.pop();

              long long x;
              if(c=="/")
              x=b/a;
              else if(c=="+")
              x=a+b;
              else if(c=="-")
              x=b-a;
              else if(c=="*")
              x=b*a;

              st.push(x);
           }
           else
           st.push(stoll(c));
        }
        return (int)st.top();
    }
};