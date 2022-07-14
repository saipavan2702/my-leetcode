class Solution {
public:
    bool wordBreak(string s,vector<string>&word) {
        int n;n=s.size();
        unordered_set<string>dict;
        for(auto x:word)
        dict.insert(x);
        
        queue<int>q;
        unordered_set<int>st;
        q.push(0);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            if(st.find(i)==st.end())
            {
                st.insert(i);
                for(int j=i;j<n;j++)
                {
                    string str=s.substr(i,j-i+1);
                    if(dict.find(str)!=dict.end())
                    {
                        q.push(j+1);
                        if(j==n-1)
                        return 1;
                    }
                    
                }
            }
        }
        return 0;
        
    }
};