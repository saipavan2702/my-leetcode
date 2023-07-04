class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        unordered_map<char,int>dict;
        int j=0;
        int ans=0;
        for(int i=0;i<n;i++){
            dict[s[i]]++;
            while(dict[s[i]]>1 and j<n){
                dict[s[j]]--;
                j++;
            }
            ans=max(ans,i-j+1);
        }
        return ans;
    }
};