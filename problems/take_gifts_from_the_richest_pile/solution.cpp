class Solution {
public:
    long long pickGifts(vector<int>& g, int k) {
        long long s=0;
        priority_queue<long long>pq;
        for(int i:g)
            pq.push(i);
        
        while(k--) {
            long long curr=pq.top();
            pq.pop();
            long long f=floor(sqrtl(curr));
            pq.push(f);
        }
        while(!pq.empty())
            s+=pq.top(),pq.pop();
        
        return s;
        
    }
};