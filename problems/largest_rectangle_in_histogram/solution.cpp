class Solution {
public:
    using pI=pair<int,int>;

    int largestRectangleArea(vector<int>& h) {
        stack<pI>st;
        int n=h.size();

        vector<int>ans(n);
        for(int i=0;i<n;i++){
            int span=1;
            while(!st.empty() && st.top().first>=h[i]){
                span+=st.top().second;
                st.pop();
            }
            st.push({h[i],span});
            ans[i]+=span*h[i];
        }

        while(st.size())st.pop();

        for(int i=n-1;i>=0;i--){
            int span=1;
            while(!st.empty() && st.top().first>=h[i]){
                span+=st.top().second;
                st.pop();
            }
            st.push({h[i],span});
            ans[i]+=(span-1)*h[i];
        }

        return *max_element(ans.begin(),ans.end());

    }
};