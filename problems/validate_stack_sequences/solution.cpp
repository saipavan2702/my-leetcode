class Solution {
public:
    bool validateStackSequences(vector<int>& pu, vector<int>& pop) {
        int n=pu.size();

        stack<int>st;
        int j=0;
        for(int i=0;i<n;i++){
            st.push(pu[i]);
            while(!st.empty() && st.top()==pop[j]){
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};