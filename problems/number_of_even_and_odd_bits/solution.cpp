class Solution {
public:
    vector<int> evenOddBit(int n) {
        bitset<32>bt(n);
        int eve=0,odd=0;
        
        for(int i=0;i<32;i++){
            if(bt[i]==1 && i&1)
                odd++;
            else if(bt[i]==1 && i%2==0)
                eve++;
                
        }
        return {eve,odd};
    }
};