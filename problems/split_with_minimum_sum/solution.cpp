class Solution {
public:
    int cntDig(int n) {
        if(n==0)
        return 1;

        return floor(log10(n)+1);
    }
    int splitNum(int num) {
        
        int len=cntDig(num);
        
        string s=to_string(num);
        
        sort(begin(s),end(s));
        int i=0,j=1;
        string l="";
        string r="";
        
        while(i<len || j<len){
            l+=s[i];
            i+=2;
            
            r+=s[j];
            j+=2;
        }
         
        int lh=stoi(l);
        int rh=stoi(r);
        
        return lh+rh;
        
    }
};