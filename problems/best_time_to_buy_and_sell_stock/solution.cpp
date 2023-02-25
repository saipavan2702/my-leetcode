class Solution {
public:
    int maxProfit(vector<int>& P) {
        int n=size(P);
        int lo(1e9),can(-1e9);

        for(int i=0;i<n;i++){
            if(P[i]<lo)
            lo=P[i];

            can=max(can,P[i]-lo);
        }
        return can;

    }
};