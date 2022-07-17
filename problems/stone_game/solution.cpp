class Solution {
public:
    bool stoneGame(vector<int>& p) {
        int cnt=0;
        for(int i=0;i<p.size();i++)
        {
            if(p[i]&1)
            cnt++;
        }
        if(cnt&1)
        return 1;
        else
        return 0;
    }
};