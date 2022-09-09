class Solution {
public:
    static bool use(vector<int>&a,vector<int>&b)
    {
        if(a[0]==b[0])
        return a[1]>b[1];
        
        return a[0]<b[0];
    }
    int numberOfWeakCharacters(vector<vector<int>>& prop) {
        int n;
        n=prop.size();
        
        int res=INT_MIN,cnt=0;
        sort(prop.begin(),prop.end(),use);
        for(int i=n-1;i>=0;i--)
        {
            if(prop[i][1]<res)
            cnt++;
            
            res=max(res,prop[i][1]);
        }
        return cnt;
        
       
    }
};