class Solution {
public:
    int distanceTraveled(int T, int aT) {
        int div=T/5;
        int rem=T%5;
        
        int ans=0;
        // ans+=(T*10);
        int u=T;
        
        while(1){
            if(u>=5){
                u-=5;
                ans+=(5*10);
                if(aT>0)
                u++,aT--;
            }else
                break;
        }
        ans+=u*10;
        return ans;
    }
};