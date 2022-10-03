class Solution {
public:
    int minCost(string col, vector<int>&T) {
        int n;
        n=col.size();
        
        int curr=0;
        stack<pair<char,int>>st;
        for(int i=0;i<n;i++)
        {
           if(!st.empty() and st.top().first==col[i])
           {
               if(st.top().second<T[i])
               {
                   curr+=st.top().second;
                   st.pop();
                   st.push({col[i],T[i]});
               }
               else
               curr+=T[i];
           }
           else
           st.push({col[i],T[i]});
        }
        return curr;
    }
};