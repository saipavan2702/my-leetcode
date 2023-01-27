class Solution {
public:
    bool check(string p, set<string>&st){
        int n=p.size();
        for(int i=1;i<n;i++){
            string pref=p.substr(0,i);
            string suff=p.substr(i);
            if(st.find(pref)!=st.end() && (st.find(suff)!=st.end() || check(suff,st)))
            return 1;
        }
        return 0;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& D) {
        set<string>st;
        vector<string>ans;

        for(auto &x:D)
        st.insert(x);

        for(auto &x:D) {

           if(check(x,st))
           ans.push_back(x);
        }
        return ans;
    }
};