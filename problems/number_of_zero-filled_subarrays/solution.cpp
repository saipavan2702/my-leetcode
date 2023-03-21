class Solution {
public:
    long long zeroFilledSubarray(vector<int>& A) {
        long long h=0;
        int n=size(A);

        stack<int>st;
        for(int i=0;i<n;i++){
            if(A[i]==0){
                st.push(0);
            }else{
                if(!st.empty()){
                    while(!st.empty()){
                        int r=st.size();
                        h+=r;
                        st.pop();
                    }
                }
            }
        }
        if(!st.empty()){
            while(!st.empty()){
                int r=st.size();
                h+=r;
                st.pop();
            }
        }
        return h;

    }
};