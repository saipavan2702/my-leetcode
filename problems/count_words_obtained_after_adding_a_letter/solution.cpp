class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        int cnt=0;
        unordered_set<string>st;
        for(auto &x:startWords)
        {
            sort(x.begin(),x.end());
            st.insert(x);
        }
        for(auto&x:targetWords)
        {
            string s="";
            sort(x.begin(),x.end());
            int n;
            n=x.size();
            for(int i=0;i<n;i++)
            {
                s=x.substr(0,i)+x.substr(i+1);
                if(st.find(s)!=st.end())
                {
                  cnt++;
                  break;
                }
            }
            
        }
        return cnt;
    }
};