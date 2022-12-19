class Solution {
public:
    int minimumCardPickup(vector<int>&s) {
        int n;
        n=s.size();
        
        int len=INT_MAX;
        unordered_map<int,int>pref;
        for(int i=0;i<n;i++)
        {
            if(pref.count(s[i]))
            len=min(len,i-pref[s[i]]+1);
            
            pref[s[i]]=i;
        }
        return len==INT_MAX?-1:len;
    }
};