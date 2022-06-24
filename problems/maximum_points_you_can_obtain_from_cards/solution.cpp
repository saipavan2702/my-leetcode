class Solution {
public:
    int maxScore(vector<int>& card, int k) {
        int n,sum=0,res;
        n=card.size();
        for(int i=n-1;i>=n-k;i--)
        {
            sum+=card[i];
        }
        int j;
        j=n-k;
        res=sum;
        for(int i=0;i<n-k and k>0;i++,k--,j++)
        {
            res=max(res,sum+=card[i]-card[j]);
        }
        return res;
        
    }
};