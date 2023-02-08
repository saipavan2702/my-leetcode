class Solution {
public:
    int minimumRecolors(string b, int k) {
        int n=b.size();
        int i=0,j=0,v=0,u=INT_MAX;
        while(i<n){
            if(b[i]=='W')
            v++;
            if(i-j+1==k){
                u=min(v,u);
                if(b[j]=='W')
                v--;

                j++;
            }
            i++;
        }
        return u;
    }
};