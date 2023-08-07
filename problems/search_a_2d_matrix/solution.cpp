class Solution {
public:
    // int check(vector<int>v,int t){
    //     int p=v.size();
    //     int lo(0),hi(p-1);
    //     while(lo<=hi){
    //         int u=(lo+hi)/2;
    //         if(v[u]==t) return u;
    //         else if(v[u]>t) hi=u-1;
    //         else lo=u+1;
    //     }
    //     return lo;
    // }
    bool searchMatrix(vector<vector<int>>& G, int t) {
        // int n=G.size(),p=G[0].size();

        // for(int i=0;i<n;i++){
        //     int idx=check(G[i],t);
        //     if(G[i][idx]==t) return true;
        // }
        // return false;
        int n,p;
        n=G.size();
        p=G[0].size();
        
        int s=0;
        int l=0,r=p-1;
        while(l<n and r>=0)
        {
            if(G[l][r]<t)
                l++;
            else if(G[l][r]>t)
                r--;
            else if(G[l][r]==t)
            return 1;
        }
        return 0;
    }
};