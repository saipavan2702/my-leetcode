class Solution {
public:
    using pI=pair<int,int>;
    long long maxScore(vector<int>& A, vector<int>& B, int k) {
        int n=A.size();
        
        vector<pI>have;
        for(int i=0;i<n;i++){
            have.push_back({B[i],A[i]});
        }

        sort(have.begin(),have.end(),[](const pI& a, const pI& b){
            return a.first>b.first;
        });

        priority_queue<int, vector<int>, greater<int>>pq;

        long long curr=0,got=0;
        for(auto x:have){
            pq.push(x.second);
            curr+=x.second;
            if(pq.size()>k){
                curr-=pq.top();
                pq.pop();
            }

            if(pq.size()==k)
            got=max(got,curr*x.first);

        }
        return got;
    }
};