class Solution {
public:
  using vi=vector<int>;
  using ll=long long;
  int maxNumberOfAlloys(int n, int k, int bud, vector<vi>& C, vi& stock, vi& cost) {
    ll lo=0,hi=1e9;
    
    function<bool(ll)>test=[&](ll u)->bool{
      ll Tcst=INT_MAX;
      for(int i=0;i<k;i++){
       ll cst=0;
        for(int j=0;j<n;j++){
          ll have=u*C[i][j];
          if(stock[j]<have) {
            ll need=(have-stock[j])*cost[j];
            cst+=need;
          }
        }
        Tcst=min(cst,Tcst);
      }
      return Tcst<=bud;
    };
    
    while(lo<=hi){
      ll u=(lo+hi)/2;
      if(test(u)) lo=u+1;
      else hi=u-1;
    }
    return lo-1;

  }
};