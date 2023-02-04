class Solution {
public:
    int maxCount(vector<int>& b, int n, int S) {
        int u=0;
        set<int>st;
        
        for(int i:b){
            st.insert(i);
        }
        
        for(int i=1;i<=n;i++) {
            
            if(S>=i && st.find(i)==st.end()) {
                cout<<S<<endl;
                S-=i;
                u++;
            }
        }
        return u;
    }
};