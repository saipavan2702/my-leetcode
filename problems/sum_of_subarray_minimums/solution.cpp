class Solution {
public:
    const int MOD=1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size();

        stack<int>st;
        vector<int>pse(n,-1),nse(n,n);

        for(int i=0;i<n;i++){
            if(st.empty())
            st.push(i);
            else{
                while(!st.empty() && arr[st.top()]>=arr[i]){
                    st.pop();
                }
                if(!st.empty())
                pse[i]=st.top();

                st.push(i);
            }
        }

        while(st.size())st.pop();

        for(int i=n-1;i>=0;i--){
            if(st.empty())
            st.push(i);
            else{
                while(!st.empty() && arr[st.top()]>arr[i]){
                    st.pop();
                }
                if(!st.empty())
                nse[i]=st.top();

                st.push(i);
            }
        }
        long long cnt=0;
        for(int i=0;i<n;i++){
            long long prev=i-pse[i];
            long long nxt=nse[i]-i;
            cnt=(cnt+prev*nxt*arr[i])%MOD;
        }
        return (int)cnt%MOD;
    }
};