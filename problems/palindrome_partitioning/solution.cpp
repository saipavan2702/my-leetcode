class Solution {
public:
    vector<vector<string>>ans;
    bool check(int lo, int hi, string s) {
        while(lo<=hi){
            if(s[lo]!=s[hi])
            return 0;

            lo++;
            hi--;
        }
        return 1;
    }
    void recur(int x, vector<string>&p, string s){
        int n=s.size();
        if(x==n){
            ans.push_back(p);
            return;
        }
        for(int i=x;i<n;i++){
            if(check(x,i,s)){
              p.push_back(s.substr(x,i-x+1));
              recur(i+1,p,s);
              p.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string>p;
        recur(0,p,s);
        return ans;
    }
};