class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<string>res;
        int freq[26]={0};
        for(auto &x:words2)
        {
            int being[26]={0};
            for(auto&y:x)
            {
                being[y-'a']++;
            }
            for(int i=0;i<26;i++)
            {
                freq[i]=max(freq[i],being[i]);
            }
        }
        for(auto &x:words1)
        {
            int cnt[26]={0};
            for(auto&y:x)
            {
                cnt[y-'a']++;
            }
            bool t=1;
            for(int i=0;i<26;i++)
            {
                if(cnt[i]<freq[i])
                t=0;
            }
            if(t)
            res.push_back(x);
        }
        return res;
    }
};