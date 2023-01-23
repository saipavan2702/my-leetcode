class Solution {
public:
    int findJudge(int n, vector<vector<int>>&T) {
        int P[10000]={0};
        for(auto x:T){
            P[x[0]]--;
            P[x[1]]++;
        }
        for(int i=1;i<=n;i++)
        if(P[i]==n-1)
        return i;

        return -1;;
    }
};