class Solution {
public:
    /*long long int fact(int k)
    {
        long long int val=1;
        if(k==0)
        return 1;
        while(k!=0)
        {
          val*=k;
            k--;
        }
        return val;
    }
    long long int ncr(int n,int r)
    {
        long long int ans;
        ans=fact(n)/(fact(n-r)*fact(r));
        return ans;
    }*/
    vector<vector<int>> generate(int n) {
        vector<vector<int>>res;
        for(int i=0;i<n;i++)
        {
            vector<int>ans(i+1,1);
            for(int j=1;j<i;j++)
            {
             ans[j]=res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(ans);
        }
        return res;
        
    }
};