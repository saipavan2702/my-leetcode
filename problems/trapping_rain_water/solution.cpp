class Solution {
public:
    int trap(vector<int>& h) {
         int n;
        n=h.size();
        long long int temp=0,ans=0,res=0;
        int r=0,l=n-1;
        while(l>r)
        {
         temp=h[h[r]<h[l]?r++:l--];
         ans=max(temp,ans);
         res+=(ans-temp);
        }
        return res;
    }
};