class Solution {
public:
    int minStoneSum(vector<int>& P, int k) {
        int n;
        n=P.size();

        priority_queue<int>pq;
        int ret=0;

        for(int i:P)
        pq.push(i),ret+=i;
        
        while(k--){
          int curr=pq.top();
          pq.pop();
          ret-=curr;
          curr-=floor(curr/2);
          ret+=curr;

          pq.push(curr);
        }
        return ret;
    }
};