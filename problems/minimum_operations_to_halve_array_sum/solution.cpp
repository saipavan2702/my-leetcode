class Solution {
public:
    int halveArray(vector<int>& nums) {
        double T=0;
        priority_queue<double>pq;

        for(int x:nums)
        {
            pq.push(x);
            T+=x;
        }
        double r=T/2;
        long long cnt=0;
        while(T>r)
        {
           double curr=pq.top();
           pq.pop();
           curr/=2;
           cnt++;
           T-=curr;
           pq.push(curr);
        }
        return cnt;
    }
};