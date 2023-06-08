class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();

        int depth(0);
        stack<int>st;
        vector<int>left(n,-1),right(n,-1);

        for(int i=0;i<n;i++){
            if(st.empty())
            st.push(h[i]);
            else{
                while(!st.empty() && st.top()<=h[i]){
                    st.pop();
                }

                if(!st.empty())
                left[i]=st.top();
                
                if(st.empty() || h[i]>st.top())
                st.push(h[i]);
            }
        }

        while(st.size())st.pop();

        for(int i=n-1;i>=0;i--){
            if(st.empty())
            st.push(h[i]);
            else{
                while(!st.empty() && st.top()<=h[i])
                st.pop();

                if(!st.empty())
                right[i]=st.top();

                if(st.empty() || h[i]>st.top())
                st.push(h[i]);
            }
        }

        for(int i=0;i<n;i++){
            if(left[i]!=-1 && right[i]!=-1)
            depth+=min(left[i]-h[i],right[i]-h[i]);
        }
        return depth;

    }
};