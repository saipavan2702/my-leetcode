class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& r) {
        int n;
        n=r.size();

        unordered_set<int>st;

        queue<int>q;
        q.push(0);
        while(!q.empty())
        {
            int i=q.front();
            q.pop();
            st.insert(i);
            for(auto u:r[i])
            {
               if(st.find(u)==st.end())
               q.push(u);
            }
        }
        return st.size()==n;
    }
};