class Solution {
public:
    int maxLengthBetweenEqualCharacters(string s) {
        unordered_map<char, int> ind;
        int ans=-1;
        int n=s.size();
        for(int i=0;i<n;i++){
            char pre=s[i];
            if(ind.count(pre)) ans=max(ans,i-ind[pre]-1);
            else ind[pre]=i;
        }
        return ans;
    }
};