class Solution {
public:
    vector<int> secondGreaterElement(vector<int>& A) {
        int n=A.size();
        vector<int>nsg(n,-1);
        stack<int>st,nge,dup;
        

        for(int i=0;i<n;i++){

            while(!nge.empty() && A[nge.top()]<A[i])
            nsg[nge.top()]=A[i],nge.pop();

            while(!st.empty() && A[st.top()]<A[i])
            dup.push(st.top()),st.pop();

            while(!dup.empty())
            nge.push(dup.top()),dup.pop();

            st.push(i);
        }

        return nsg;
    }

    //n=5
    //2 4 0 9 6
//nge 1 3 3 5 5
//nsg 
};