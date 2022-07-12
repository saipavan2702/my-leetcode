class Solution {
public:
    bool dict(vector<int>&s,vector<bool>&vis,int rsum,int curr,int i,int k)
    {
        if(k==1)
        return 1;
        int n;n=s.size();
        if(curr==rsum)
        {
            return dict(s,vis,rsum,0,0,k-1);
        }
        for(int j=i;j<n;j++)
        {
            if(curr+s[j]<=rsum and !vis[j])
            {
                vis[j]=1;
             if(dict(s,vis,rsum,curr+s[j],j+1,k))
             return 1;
            
             vis[j]=0;
            } 
        }
        return 0;
    }
    bool makesquare(vector<int>&s) {
      int n;n=s.size();
       int k=4;
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
        
       vector<bool>vis(n,0);
        sort(s.begin(),s.end());
        reverse(s.begin(),s.end());
        return dict(s,vis,rsum,0,0,k);
        
    }
};