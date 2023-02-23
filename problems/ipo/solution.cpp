class Solution {
public:
    using pI=pair<int,int>;
    int findMaximizedCapital(int k, int need, vector<int>& P, vector<int>& C) {
        int n=P.size();

        vector<pI>can;

        for(int i=0;i<n;i++)
        can.push_back({C[i],P[i]});

        sort(begin(can),end(can));
        priority_queue<int>pq;

        int i=0;
        while(k--){
            while(i<n && can[i].first<=need){
                pq.push(can[i].second);
                i++;
            }
            if(!pq.empty())
            need+=pq.top(),pq.pop();
        }
        return need;
    }
};