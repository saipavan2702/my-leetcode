class Solution {
public:
    long long totalCost(vector<int>& cost, int k, int can) {
        int n=cost.size();
        int i=0,j=n-1;
        using pC=pair<int,bool>;
        long long hav=0;

        priority_queue<pC, vector<pC>, greater<pC>>pq;
        for(int x=0;x<can;x++)
        pq.push({cost[i],0}),i++;

        for(int x=0;x<can && i<=j;x++)
        pq.push({cost[j],1}),j--;


        while(k--){
            pC node=pq.top();
            pq.pop();

            bool h=node.second;
            hav+=node.first;

            if(i<=j){
                if(h)
                pq.push({cost[j],1}),j--;
                else
                pq.push({cost[i],0}),i++;
            }
        }
        return hav;
    }
};