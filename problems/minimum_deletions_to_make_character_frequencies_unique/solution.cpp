class Solution {
public:
    int minDeletions(string s) {
        int cnt=0;
        map<char,int>freq;
        for(auto x:s)
        {
            freq[x]++;
        }
        set<int>st;
        for(auto x:freq)
        {
            while(st.find(x.second)!=st.end())
            {
                x.second--;
                cnt++;
            }
            if(x.second!=0)
            st.insert(x.second);
        }
        return cnt;
        
    }
};