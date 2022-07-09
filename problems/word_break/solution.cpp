class Solution {
public:
    bool wordBreak(string s, vector<string>& words) {
        int n;n=s.size();
    vector<bool>vis(n+1,0);
    vis[0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<i;j++)
        {
        auto it=find(words.begin(),words.end(),s.substr(j,i-j));
            if(vis[j] and it!=words.end())
            {
                vis[i]=1;
                break;
            }
        }
    }
        return vis.back();
    }
};