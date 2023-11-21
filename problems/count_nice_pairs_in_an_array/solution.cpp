class Solution {
private:
    int rev(int n){
        int R=0;
        while(n){
            R=(R*10+n%10);
            n/=10;
        }
        return R;
    }
public:
    const int MOD=1e9+7;
    int countNicePairs(vector<int>& A) {
        using ll=long long;
        ll ans=0;
        unordered_map<int,ll>freq;

        for(auto x:A) freq[x-rev(x)]++;
        for(auto [x,y]:freq){
            ans=(ans+(y*(y-1))/2)%MOD;
        }
        return ans;
    }
};


