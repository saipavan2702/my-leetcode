class Solution {
public:
    int miceAndCheese(vector<int>& S, vector<int>& T, int k) {
        int n=S.size();
        
        long long ans=0;
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            pq.push(S[i]-T[i]);
            ans+=T[i];
        }
        
        while(k--){
            auto x=pq.top();
            ans+=x;
            pq.pop();
        }
    
        return ans;
        
    }
};