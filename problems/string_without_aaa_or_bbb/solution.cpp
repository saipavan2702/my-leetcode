class Solution {
public:
    string strWithout3a3b(int a, int b) {
        string s="";
        int la=0,lb=0;
        
        while(a>0 || b>0){
            if((a>=b and la<2) or (lb>=2)){
                s+='a';
                la++;
                lb=0;
                a--;
            }else{
                s+='b';
                lb++;
                la=0;
                b--;
            }
        }
        return s;
    }
};