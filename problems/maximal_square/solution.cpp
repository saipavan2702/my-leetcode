class Solution {
public:
    int maximalSquare(vector<vector<char>>& G) {
        int n=G.size();
        int p=G[0].size();

        vector<int>a(p+1,0);
        int can=0;

        auto  get=[&](vector<int>a){
            stack<pair<int,int>>st;
            st.push({0,-1});

            int k=a.size();
            int ans=0;
            for(int i=0;i<k;i++) {
                if(a[i]>st.top().first)
                st.push({a[i],i});
                else{
                    while(!st.empty() && st.top().first>a[i]){
                        int ht=st.top().first;
                        st.pop();
                        int bf=i-st.top().second-1;
                        ans=max(ans,min(ht*ht,bf*bf));
                    }
                    st.push({a[i],i});
                }
            }
            return ans;
        };

       

        for(int i=0;i<n;i++){
            for(int j=0;j<p;j++){
               if(G[i][j]=='0')
               a[j]=0;
               else
               a[j]++;
            }
            can=max(can,get(a));
        }

        return can;
    }
};