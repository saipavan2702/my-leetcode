class Solution {
public:
    int singleNumber(vector<int>& A) {
        int ones=0,twos=0;

        for(int i:A){
            ones=(ones^i) & (~twos);
            twos=(twos^i) & (~ones);
        }
        return ones;
    }
};