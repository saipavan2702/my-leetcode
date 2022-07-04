class Solution {
public:
    int maxArea(vector<int>& h) {
        int n;
        n=h.size();
        int ans=0;
        int r=0,l=n-1;
        while(l>r)
        {
         int ht=min(h[r],h[l]);
         ans=max(ans,(l-r)*ht);
            
         while(ht>=h[r] and r<l)
         r++;
            
         while(ht>=h[l] and l>r)
         l--;
        }
        return ans;
    }
};