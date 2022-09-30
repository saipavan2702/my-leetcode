class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& b) {
        vector<vector<int>>ans,walls;
        for(auto x:b)
        {
            walls.push_back({x[0],-x[2]});
            walls.push_back({x[1],x[2]});
        }
        
        sort(walls.begin(),walls.end());
        
        multiset<int>st={0};
        int top=0;
        for(auto x:walls)
        {
            if(x[1]<0)
            st.insert(-x[1]);
            else
            st.erase(st.find(x[1]));
            
            if(*st.rbegin()!=top)
            ans.push_back({x[0],top=*st.rbegin()});
            
        }
        return ans;
    }
};