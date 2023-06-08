class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& A) {
        int n=A.size();
        vector<int>can(n);

        stack<int>st;
        for(int i=2*n-1;i>=0;i--){
            if(st.empty())
            st.push(A[i%n]);
            else{
                while(!st.empty() && st.top()<=A[i%n])st.pop();

                if(st.empty())can[i%n]=-1;
                else can[i%n]=st.top();

                st.push(A[i%n]);
            }
        }

        return can;
    }
};