class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n=s.size();
        int z=count(s.begin(),s.end(),'0');

        int u=z,v=0;
        for(int i=0;i<n;i++){
            if(s[i]=='0')
            z--;
            else
            v++;

            u=min(u,v+z);
        }
        return u;
    }
};