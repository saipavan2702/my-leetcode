class Solution {
public:
    int lastStoneWeight(vector<int>& S) {
        priority_queue<int>pq(S.begin(),S.end());

        while(pq.size()>1){
            int a=pq.top();
            pq.pop();
            int b=pq.top();
            pq.pop();

            if(a==b)
            continue;
            else
            pq.push(abs(a-b));
        }
        return pq.empty()?0:pq.top();
    }
};