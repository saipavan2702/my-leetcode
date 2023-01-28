class Solution {
public:
    int alternateDigitSum(int n) {
        int sgn=1;
        int s=0;
        int u=n,cnt=0;
        while(u!=0){
            cnt++;
            u/=10;
        }
        cnt--;
        while(cnt>=0){
            int p=pow(10,cnt);
            int l=n/p;
            cout<<s;
            s+=(l*sgn);
            sgn=-sgn;
            n-=l*p;
            cnt--;
        }
        return s;
    }
};