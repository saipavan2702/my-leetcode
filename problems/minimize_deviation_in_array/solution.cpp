class Solution {
public:
    int minimumDeviation(vector<int>& A) {
        priority_queue<int>pq;
        for(int &i:A){
            if(i&1)
            i<<=1;

            pq.push(i);
        }
        int s=*min_element(begin(A),end(A));
        int hash=INT_MAX;

        while(!pq.empty()) {

            int x=pq.top();
            pq.pop();
            
            hash=min(hash,x-s);
            if(x&1)
            break;

            s=min(s,x/2);
            pq.push(x/2);
        }
        return hash;
    }
};