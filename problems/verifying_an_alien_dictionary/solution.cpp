class Solution {
public:
    bool isAlienSorted(vector<string>&s, string p) {
        vector<int>dict(26,-1);
        int i=0;
        for(auto &x:p) {
            dict[x-'a']=i;
            i++;
        }
        for(auto &u:s){
            for(auto &v:u){
                v=dict[v-'a'];
            }
        }
        return is_sorted(begin(s),end(s));
    }
};