class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int>res;
        int n,p,q;
        n=s.size();
        p=words.size();
        q=words[0].size();
        unordered_map<string,int>freq;
        for(auto &x:words)
        freq[x]++;
        
        for(int i=0;i<n-p*q+1;i++)
        {
            unordered_map<string,int>dict;
            int j=0;
            while(j<p)
            {
                string str=s.substr(i+j*q,q);
                if(freq[str])
                {
                 dict[str]++;
                 if(freq[str]<dict[str])
                 break;
                }
                else
                break;
                j++;
            }
            if(j==p)
            res.push_back(i);
        }
        return res;
    }
};