class Solution {
public:
    int countOdds(int lo, int hi) {
        return ceil(hi*1.0/2)-lo/2;
    }
};