class Solution {
public:
    vector<int> successfulPairs(vector<int>& s, vector<int>& t, long long success) {
        int i,n,m,j;
        n=s.size();
        m=t.size();
        vector<int>ans;
        vector<long long int>res;
        for(i=0;i<n;i++)
        {
           if(success%s[i]!=0)
           {long long x;
            x=ceil(success*1.0/s[i]);
           res.push_back(x);}
           else
           {long long y;
            y=success/s[i];
           res.push_back(y);}    
        }
        sort(t.begin(),t.end());
        for(auto i:res)
        {
            auto it=lower_bound(t.begin(),t.end(),i);
            j=t.end()-it;
            
            ans.push_back(j);
        }    
        return ans;
    }
};