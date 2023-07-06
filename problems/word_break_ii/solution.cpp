class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& D) {
        int n=s.size();
        vector<string>ans;
        unordered_set<string>st(D.begin(),D.end());

        function<void(int,string)>recur=[&](int i, string have){
            if(i==n){
                have.pop_back();
                ans.push_back(have);
                return;
            }
            for(int j=i;j<n;j++){
                string u=s.substr(i,j-i+1);
                if(st.find(u)!=st.end()){
                    recur(j+1,have+u+" ");
                }
            }
        };
        recur(0,"");
        return ans;
    }
};