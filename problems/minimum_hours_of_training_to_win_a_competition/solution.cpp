class Solution {
public:
    int minNumberOfHours(int y, int e, vector<int>& energy, vector<int>& exp) {
        int n;
        n=energy.size();
        int sum=accumulate(energy.begin(),energy.end(),0);
        int cnt=0;
        if(y<=sum)
        {
            cnt+=(sum-y)+1;
             y=sum+1;
        }
        for(int i=0;i<n;i++)
        {
            if(e<=exp[i])
            {
                cnt+=(exp[i]-e)+1;
                e+=(exp[i]-e)+1;
            }
            e+=exp[i];
        }
        return cnt;
    }
};