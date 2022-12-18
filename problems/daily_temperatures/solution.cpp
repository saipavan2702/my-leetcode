class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        int n;
        n=t.size();

        stack<pair<int,int>>st;
        vector<int>ret(n);

        for(int i=0;i<n;i++)
        {
            while(!st.empty() and t[i]>st.top().first)
            ret[st.top().second]=i-st.top().second,st.pop();
            
            st.push({t[i],i});
        }
        return ret;
    }
};