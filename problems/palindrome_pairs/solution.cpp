class Solution {
public:
    bool isPal(const string&t,int l,int r)
    {
        while(l<r and t[l]==t[r])
        {l++;r--;}
        
        return l>=r;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        int n;
        n=words.size();
        vector<vector<int>>res;
        map<int,unordered_map<string,int>>freq;
        for(int i=0;i<n;i++)
        {
            string str=words[i];
            int r=str.size();
            freq[r][string(str.rbegin(),str.rend())]=i;
        }
        for(int i=0;i<n;i++)
        {
            string s=words[i];
            for(auto& [x,y]:freq)
            {
                if(x>s.size())
                break;
                
                if(x==s.size())
                {
                    if(y.count(s) and y[s]!=i)
                    res.push_back({i,y[s]});
                    
                    break;
                }
                if(isPal(s,x,s.size()-1))
                {
                    string a=s.substr(0,x);
                    if(y.count(a))
                    res.push_back({i,y[a]});
                }
                if(isPal(s,0,s.size()-x-1))
                {
                    string b=s.substr(s.size()-x);
                    if(y.count(b))
                    res.push_back({y[b],i});
                }
            }
        }
        return res;
    }
};