class Solution {
public:
    int longestStrChain(vector<string>& words) {
        unordered_map<string,int>dp;
        int ans=1;
        sort(words.begin(),words.end(),[&](const string& a, const string& b){
            return a.size()<b.size();
        });

        for(auto &x:words){
            dp[x]=1;
            for(int i=0;i<x.size();i++){
                auto ref=x.substr(0,i)+x.substr(i+1);
                if(dp.find(ref)!=dp.end())
                dp[x]=max(dp[x],dp[ref]+1),ans=max(ans,dp[x]);
            }
        }
        return ans;
    }
};