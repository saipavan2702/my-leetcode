class Solution {
public:
    int totalMoney(int n) {
        int have=n/7;
        int days=n%7;

        int ans=0;
        for(int i=1;i<=have;i++) ans+=(7*(i+3));
        for(int i=0;i<days;i++) ans+=(++have);
        
        return ans;
    }
};