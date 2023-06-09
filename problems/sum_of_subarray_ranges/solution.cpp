class Solution {
public:
    void clean(stack<int>&st){
        while(st.size())st.pop();
    }

    long long subArrayRanges(vector<int>& na) {
        int n=na.size();

        stack<int>st;
        vector<int>nse(n,n),pse(n,-1),nge(n,n),pge(n,-1);

        for(int i=0;i<n;i++){
            if(st.empty())
            st.push(i);
            else{
                while(!st.empty() && na[st.top()]>na[i])
                st.pop();

                if(!st.empty())
                pse[i]=st.top();

                st.push(i);
            }
        }

        clean(st);

        for(int i=n-1;i>=0;i--){
            if(st.empty())
            st.push(i);
            else{
                while(!st.empty() && na[st.top()]>=na[i])
                st.pop();

                if(!st.empty())
                nse[i]=st.top();

                st.push(i);
            }
        }

        clean(st);

        for(int i=0;i<n;i++){
            if(st.empty())
            st.push(i);
            else{
                while(!st.empty() && na[st.top()]<na[i])
                st.pop();

                if(!st.empty())
                pge[i]=st.top();

                st.push(i);
            }
        }

        clean(st);

        for(int i=n-1;i>=0;i--){
            if(st.empty())
            st.push(i);
            else{
                while(!st.empty() && na[st.top()]<=na[i])
                st.pop();

                if(!st.empty())
                nge[i]=st.top();

                st.push(i);
            }
        }

        using ll=long long;
        ll ans=0;
        for(int i=0;i<n;i++){
            ll lg=i-pge[i];
            ll ls=i-pse[i];

            ll rg=nge[i]-i;
            ll rs=nse[i]-i;

            ans+=(((rg*lg)-(ls*rs))*na[i]);
        }
        return ans;
        
    }
};