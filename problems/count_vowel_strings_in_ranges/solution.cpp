class Solution {
public:
    bool check(string z) { 
        bool x=0,y=0;
        int n=z.size();

        if(z[0] == 'a' || z[0] == 'e' || z[0] == 'i' || z[0] == 'o' || z[0] == 'u')
            x=1;
        
        if(z[n-1] == 'a' || z[n-1] == 'e' || z[n-1] == 'i' || z[n-1] == 'o' || z[n-1] == 'u')
            y=1;
        
        return x && y;
    }
    vector<int> vowelStrings(vector<string>& s, vector<vector<int>>& q) {
        int n=s.size();
        vector<int>pref(n);
        vector<int>Q;
        
        pref[0]=check(s[0]);
        
        for(int i=1;i<n;i++) {
          pref[i]=pref[i-1]+check(s[i]);  
        }
        
        for(auto x:q) {
            
            if(x[0]==0)
                Q.push_back(pref[x[1]]);
            else if(x[0]==x[1]) 
                Q.push_back(check(s[x[0]]));
            else
                Q.push_back(pref[x[1]]-pref[x[0]-1]);
            
        }
        return Q;
    }
};