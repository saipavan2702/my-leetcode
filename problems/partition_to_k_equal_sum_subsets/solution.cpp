class Solution {
public:
     bool dict(vector<int>&s,vector<int>&vis,int rsum,int x)
    {
        int n;n=s.size();
        if(x==n)
        {
            for(int i=0;i<vis.size();i++)
            {
                if(vis[i]!=rsum)
                return 0;
            }
            return 1;
        }
        for(int i=0;i<vis.size();i++)
        {
            if (s[x]+vis[i]<=rsum)
            {
             vis[i]+=s[x];
            if(dict(s,vis,rsum,x+1))
             {return 1;}
                
             vis[i]-=s[x];
             if(vis[i]==0)
             break;
            }
           
        }
        return 0;
    }
    bool canPartitionKSubsets(vector<int>&s, int k) {
        int n;n=s.size();
       if(n<k)
       return 0;
       int sum=0;
       for(int x:s)
       {
         sum+=x;
       }
       if(sum%k!=0)
       return 0;
        
       int rsum;
       rsum=sum/k;
        
       vector<int>vis(k,0);
        return dict(s,vis,rsum,0);
    }
};