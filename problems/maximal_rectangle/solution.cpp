class Solution {
public:
    int maximalRectangle(vector<vector<char>>& G) {
        int n=G.size();
        int p=G[0].size();

        vector<vector<int>>h(n,vector<int>(p,0));
        for(int i=0;i<p;i++)
        h[0][i]=(G[0][i]=='1');

        for(int i=1;i<n;i++){
            for(int j=0;j<p;j++){
                (G[i][j]=='1')?h[i][j]=h[i-1][j]+1:h[i][j]=0;
            }
        }

        int can=0;
        auto get=[&](vector<int> a){
            stack<pair<int,int>>st;
            vector<int>ans(p);

            for(int i=0;i<p;i++){
                int span=1;
                while(!st.empty() && st.top().first>=a[i]){
                    span+=st.top().second;
                    st.pop();
                }
                st.push({a[i],span});
                ans[i]+=span*a[i];
            }

            while(st.size())st.pop();

            for(int i=p-1;i>=0;i--){
                int span=1;
                while(!st.empty() && st.top().first>=a[i]){
                    span+=st.top().second;
                    st.pop();
                }
                st.push({a[i],span});
                ans[i]+=(span-1)*a[i];
            }

            return *max_element(ans.begin(),ans.end());
        };


        for(int i=0;i<n;i++){
            can=max(can,get(h[i]));
        }
        return can;
    }
};