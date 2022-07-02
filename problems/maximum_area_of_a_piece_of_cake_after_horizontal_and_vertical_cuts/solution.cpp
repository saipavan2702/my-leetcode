class Solution {
public:
    int maxArea(int h, int v, vector<int>& hc, vector<int>& vc) {
        sort(hc.begin(),hc.end());
        sort(vc.begin(),vc.end());
        int res,sus;
        int n,m;
        m=vc.size();
        n=hc.size();
        
        res=max(hc[0],h-hc[n-1]);
        for(int i=1;i<n;i++)
        {
            res=max(res,hc[i]-hc[i-1]);
        }
       
        sus=max(vc[0],v-vc[m-1]);
        
        for(int i=1;i<m;i++)
        {
            sus=max(sus,vc[i]-vc[i-1]);
        }
        
        return (1LL*res*sus) % 1000000007;
        
    }
};