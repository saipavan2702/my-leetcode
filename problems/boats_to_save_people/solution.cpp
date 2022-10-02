class Solution {
public:
    int numRescueBoats(vector<int>& p, int l) {
        int n;
        n=p.size();
        int i=0,j=n-1,r=0;
        sort(p.begin(),p.end());
        while(i<=j)
        {
            int curr=p[j];
            j--;
            
            if(curr+p[i]<=l)
            i++;
            
            r++;
        }
        return r;
    }
};