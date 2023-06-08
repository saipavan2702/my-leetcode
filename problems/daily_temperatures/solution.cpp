class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n;
        n=t.size();

        stack<pair<int,int>>st;
        vector<int>ret(n);

        // for(int i=0;i<n;i++)
        // {
        //     while(!st.empty() and t[i]>st.top().first)
        //     ret[st.top().second]=i-st.top().second,st.pop();
            
        //     st.push({t[i],i});
        // }

       for(int i=n-1;i>=0;i--){
           if(st.empty())
           st.push({t[i],i});
           else if(!st.empty()){
               while(!st.empty() && st.top().first<=t[i]){
                   st.pop();
               }

               if(st.empty())
               ret[i]=0;
               else
               ret[i]=st.top().second-i;
           }

           st.push({t[i],i});
       }
       return ret;
    }
};