class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int x=1,n;n=s.size();
        if(n==0)
        return 0;
        int r=0,l=1;
        unordered_set<char>st;
        st.insert(s[0]);
        while(r<n-1 and l<n)
        {
            if(!(st.find(s[l])!=st.end()))
            {
                x=max(l-r+1,x);
                st.insert(s[l]);
                l++;
            }
            else
            {
                st.erase(s[r]);
                r++;
            }
        }
        return x;
    }
};