class Solution {
public:
    int largestOverlap(vector<vector<int>>&a, vector<vector<int>>&b) {
        int n;
        n=a.size();
        
        vector<pair<int,int>>ret,top;
       
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(a[i][j]==1)
                ret.push_back({i,j});
                
                if(b[i][j]==1)
                top.push_back({i,j});
            }
        }
        int ans=0;
        map<pair<int,int>,int>freq;
        for(auto [i,j]:ret)
        {
            for(auto [x,y]:top)
            {
                freq[{i-x,j-y}]++;
                ans=max(ans,freq[{i-x,j-y}]);
            }
        }
        return ans;
    }
};