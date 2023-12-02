class Solution {
public:
    int countCharacters(vector<string>& W, string ch) {
        vector<int>alpha(26);
        for(auto &x:ch) alpha[x-'a']++;

        int cnt=0;
        for(auto s:W){
            vector<int>beta;
            beta=alpha;
            bool h=true;
            for(auto &x:s){
                if(beta[x-'a']<=0){
                    h=false;
                    break;
                }
                beta[x-'a']--;
            }
            if(h) cnt+=(s.size());
        }
        return cnt;
    }
};