class Solution {
public:
    void track(vector<int>&a, int t,vector<vector<int>>&res,vector<int>&feb,int i)
    {
        if(t==0)
        {
            res.push_back(feb);
            return;
        }
        while(i<a.size() and a[i]<=t)
        {
          
          feb.push_back(a[i]);
          track(a,t-a[i],res,feb,i);
            ++i;
          feb.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>&s, int t) {
        set<int>st;
        for(auto x:s)
        st.insert(x);
        
        vector<int>a;
        for(auto x:st)
        a.push_back(x);
        
        vector<vector<int>>res;
        vector<int>feb;
        track(a,t,res,feb,0);
        return res;
    }
};