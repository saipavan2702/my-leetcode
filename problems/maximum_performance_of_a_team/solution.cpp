class Solution {
public:
    int maxPerformance(int n, vector<int>& speed, vector<int>& eff, int k) {
        priority_queue<int,vector<int>,greater<int>>p;
        priority_queue<pair<int,int>>pq;
        for(int i=0;i<n;i++)
        pq.push({eff[i],speed[i]});
        
        long long int s=0;
        long long int t=0;
        while(!pq.empty())
        {
           auto x=pq.top();
           pq.pop();
           s+=x.second;
           p.push(x.second);
           if(p.size()>k)
           {
               s-=p.top();
               p.pop();
           }
           t=max(t,s*x.first);
        }
        return t%(int)(1e9+7);
    }
};