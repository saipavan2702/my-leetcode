class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        int la=0,lb=0,lc=0;
        string s="";
        while(a>0 || b>0 || c>0){
            if(c>=a and c>=b and lc<2 or la>=2 and c>0 or lb>=2 and c>0){
                s+='c';
                c--;
                lc++;
                la=0;lb=0;
            }else if(a>=c and a>=b and la<2 or lc>=2 and a>0 or lb>=2 and a>0){
                s+='a';
                a--;
                la++;
                lc=0;lb=0;
            }else if(b>=c and b>=a and lb<2 or lc>=2 and b>0 or la>=2 and b>0){
                s+='b';
                lb++;
                lc=0;la=0;
                b--;
            }else break;
        }
        return s;
    }
};