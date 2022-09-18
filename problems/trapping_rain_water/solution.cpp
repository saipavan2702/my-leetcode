class Solution {
public:
    int trap(vector<int>& ht) {
        int n,i=0;
        n=ht.size();
        int right=0,left=0,ans=0,j=n-1;
        while(i<j)
        {
            if(ht[i]>=ht[j])
            {
             if(right<ht[j])
             right=ht[j];
             else
             ans+=(right-ht[j]);
                
             j--;
            }
            else
            {
                if(left<ht[i])
                left=ht[i];
                else
                ans+=(left-ht[i]);
                
                i++;
            }
        }
        return ans;
    }
};