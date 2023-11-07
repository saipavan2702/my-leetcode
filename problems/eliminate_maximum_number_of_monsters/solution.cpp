class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        priority_queue<double,vector<double>,greater<double>>pq;
        
        int n=dist.size();
        for(int i=0;i<n;i++) pq.push(dist[i]*1.0/speed[i]);

        int T=0;
        while(!pq.empty() && T<pq.top()){
           int x=pq.top();
           pq.pop();
           T++;
        }
        return n-pq.size();
    }
};