class Solution {
public:
    int maximumRequests(int n, vector<vector<int>>& req) {
        int P[n+1];
        for(int i=0;i<n;i++)P[i]=0;

        int p=req.size();
        int take=0;
        function<void(int,int)>recur=[&](int i,int cnt)->void{
            if(i==p) {
                for(int i=0;i<n;i++)if(P[i]!=0)return;
                take=max(take,cnt);
                return;
            }
            P[req[i][0]]--;
            P[req[i][1]]++;

            recur(i+1,cnt+1);

            P[req[i][0]]++;
            P[req[i][1]]--;

            recur(i+1,cnt);
        };
        recur(0,0);
        return take;
    }
};