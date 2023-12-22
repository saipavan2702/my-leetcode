class Solution {
public:
    int maxScore(string s) {
        int n=s.size();
        vector<int>I(n),Z(n);

        Z[0]=(s[0]=='0')?1:0;
        I[n-1]=(s[n-1]=='1')?1:0;
        
        for(int i=1;i<n;i++){
            if(s[i]=='0') Z[i]=Z[i-1]+1;
            else Z[i]=Z[i-1];
        } 
        for(int i=n-2;i>=0;i--) { 
            if(s[i]=='1') I[i]=I[i+1]+1;
            else I[i]=I[i+1];
        }

        int ans=0;
        for(int i=0;i<n-1;i++){
            ans=max(ans,Z[i]+I[i+1]);
        }
        return ans;
    }
};