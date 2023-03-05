class Solution {
public:
    int passThePillow(int n, int t) {
        bool h=0;
        int i=1;
        while(t>0){
        
            if(!h){
                    i++;
                  if(i==n)
                    h=!h;
            }
            else{
                i--;
                if(i==1)
                    h=!h;
            }
            t--;
        }
        return i;
        
        
    }
};