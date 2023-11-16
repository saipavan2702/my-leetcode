class Solution {
public:
    string findDifferentBinaryString(vector<string>& A) {
        unordered_set<string>st(A.begin(),A.end());
        string ans="";

        int n=A.size();
        function<void(string,int)>recur=[&](string s, int n){
            if(n==0){
                if(st.find(s)==st.end()) ans=s;
                return;
            }
            recur(s+'0',n-1);
            recur(s+'1',n-1);
        };
        recur("",n);

        return ans;
    }
};