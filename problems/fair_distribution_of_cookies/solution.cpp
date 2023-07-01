class Solution {
public:
    int distributeCookies(vector<int>& cook, int k) {
        int n=cook.size();
        vector<int>v(k);
        int ans=1e9;

        function<void(int)>recur=[&](int x){
           if(x==n){
               ans=min(ans,*max_element(v.begin(),v.end()));
               return;
           }
            for(int i=0;i<k;i++){
                v[i]+=cook[x];
                recur(x+1);
                v[i]-=cook[x];

                if(v[i]==0)
                break;
            }
        };
        recur(0);
        return ans;
    }
};