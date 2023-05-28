class Solution {
public:
    string removeTrailingZeros(string s) {
        int n=s.size();
        
        int idx=-1;
        for(int i=n-1;i>=0;i--){
            if(s[i]!='0'){
                idx=i;
                break;
            }
        }
        if(idx==n-1)
            return s;
        
        return s.substr(0,idx+1);
    }
};