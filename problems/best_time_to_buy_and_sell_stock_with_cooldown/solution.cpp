class Solution {
public:
    int maxProfit(vector<int>&T) {
        int n;
        n=T.size();
        
        if(n==1)
        return 0;

        vector<int>buy(n,0),sell(n,0);

        buy[0]=-T[0];
        buy[1]=max(-T[0],-T[1]);
        sell[1]=max(0,-T[0]+T[1]);

        for(int i=2;i<n;i++)
        {
            buy[i]=max(buy[i-1],-T[i]+sell[i-2]);
            sell[i]=max(sell[i-1],buy[i-1]+T[i]);
        }
        return sell[n-1];
    }
};