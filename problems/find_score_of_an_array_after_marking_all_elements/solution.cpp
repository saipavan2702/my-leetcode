class Solution {
public:
    long long findScore(vector<int>& A) {
        map<int,vector<int>>freq;
        int n=size(A);
        
        for(int i=0;i<n;i++)
            freq[A[i]].push_back(i);
        
        long long h=0;
        vector<bool>vis(n,0);
        
        for(auto x:freq){
            for(auto i:x.second){
                if(!vis[i]){
                    vis[i]=1;
                    h+=x.first;
                    vis[max(i-1,0)]=1;
                    vis[min(i+1,n-1)]=1;
                }
            }
        }
        return h;
        
    }
};