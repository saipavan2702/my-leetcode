class Solution {
public:
    int bestTeamScore(vector<int>&S, vector<int>&A) {
      using pI=pair<int,int>;
      int n=A.size();
  
      vector<pI>p;
      vector<int>dp(n,0);
      
      for(int i=0;i<n;i++) {
        p.push_back({A[i],S[i]});
      }

      sort(p.begin(),p.end());

      int cy=0;
      for(int i=0;i<n;i++) {

        dp[i]=p[i].second;
        for(int j=0;j<i;j++) {

          if(p[j].second <= p[i].second) {
            dp[i]=max(dp[i],dp[j]+p[i].second);
          }
        }
        cy=max(cy,dp[i]);
      }
      return cy;
    
    }
};