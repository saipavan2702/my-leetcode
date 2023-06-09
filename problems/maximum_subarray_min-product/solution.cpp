class Solution {
public:
    const long MOD=1e9+7;
    using ll=long ;
    int maxSumMinProduct(vector<int>& na) {
        int n=na.size();

        vector<ll>preSum;

         preSum.push_back(0);
	 
     for (int i = 0; i < na.size(); i++)
        preSum.push_back(preSum.back() + na[i]);

        stack<int>st;
        vector<ll>nse(n,n),pse(n,-1);

        for(int i=0;i<n;i++){
            while(!st.empty() && na[st.top()]>=na[i])
            st.pop();

            if(!st.empty())
            pse[i]=st.top();

            st.push(i);
        }

        while(st.size())st.pop();

        for(int i=n-1;i>=0;i--){
            while(!st.empty() && na[st.top()]>=na[i])
            st.pop();

            if(!st.empty())
            nse[i]=st.top();

            st.push(i);
        }

        ll cnt=0;
        for(int i=0;i<n;i++){
            ll have=(preSum[nse[i]]-preSum[pse[i]+1])*na[i];
            cnt=max(cnt,have);
        }
        return cnt%MOD;
    }
};