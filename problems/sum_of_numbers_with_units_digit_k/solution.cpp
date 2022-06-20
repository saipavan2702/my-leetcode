class Solution {
public:
    int dp(vector<int>&ans,int n)
    {
        //Using bottom up approach
        vector<int>res(n+1,INT_MAX);
        for(int t=0;t<=n;t++)
        {
            res[0]=0;
            for(int i=0;i<ans.size();i++)
            {
                if(t>=ans[i] and res[t-ans[i]]!=INT_MAX)
                {
                    int subprob=res[t-ans[i]];
                    res[t]=min(res[t],subprob+1);
                }
            }
            
        }
        if(res[n]==INT_MAX)
        return -1;
        else
        return res[n];
    }
    int minimumNumbers(int num, int k) {
        vector<int>ans;
        for(int i=0;i<=num;i++)
        {
            if(i%10==k)
            {
                ans.push_back(i);
            }
        }
        return dp(ans,num);
    }
};