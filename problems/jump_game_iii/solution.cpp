class Solution {
public:
    bool canReach(vector<int>& arr, int S) {
        int n=arr.size();
        // int vis[50005];
        // memset(vis,0,sizeof(vis));
        vector<bool>vis(n,0);

        function<bool(int)>recur=[&](int i)->bool{
            if(i<0 or i>=n || vis[i])return 0;
            if(arr[i]==0)return 1;

            vis[i]=1;
            return recur(i-arr[i]) || recur(i+arr[i]);
        };
        return recur(S);
    }
};