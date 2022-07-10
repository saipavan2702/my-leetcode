class Solution {
public:
    int fillCups(vector<int>& a) {
        sort(a.begin(),a.end());
        int r,q,sum=0,cnt=0;
        for(auto x:a)
        {
            if(x==0)
            {
                cnt++;
            }
            sum+=x;
        }
        if(cnt==2)
        return sum;
        else if(a[0]+a[1]>a[2])
        {r=sum%2;
        q=sum/2;
        return q+r;}
        else
        return a[2];
        
    }
};