class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int x=__builtin_popcount(num2);
        int y=__builtin_popcount(num1);
        
        if(x==y)
        return num1;
        
       int r=0;
       for(int i=31;i>=0;i--)
       {
           if(x and num1&(1<<i))
           {
               r|=(1<<i);
               x--;
           }
       }
       for(int i=0;i<32;i++)
       {
           if(!(r&(1<<i)) and x)
           {
               r|=(1<<i);
               x--;
           }
       }
       return r;
        
    }
};