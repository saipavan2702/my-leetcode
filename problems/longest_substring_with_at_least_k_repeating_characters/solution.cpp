class Solution {
public:
    int longestSubstring(string s, int k) {
        int n=s.size();

        if(k==0)
        return n;
        
        int i=0,j=0;
        unordered_map<char,int>dict;
        for(auto &x:s)
        dict[x]++;

        int u=0;
        while(i<n && dict[s[i]]>=k)
        i++;

        if(i==n)
        return i;

        int node=longestSubstring(s.substr(0,i),k);

        while(i<n && dict[s[i]]<k)
        i++;

        int done=longestSubstring(s.substr(i),k);

        return max(node,done);
    }
};