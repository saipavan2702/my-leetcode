class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<int>ans;
        set<int>st;
        
        long long i=1;
        long long l=1;
        while(1){
            while(i>n){
                i-=n;
            }

            if(st.find(i)!=st.end())
                break;

            st.insert(i);
            
            i+=l*k;
            l++;
        }
        
        
        for(int i=1;i<=n;i++){
            if(st.find(i)==st.end())
                ans.push_back(i);
        }
        return ans;
    }
};