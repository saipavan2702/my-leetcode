class Solution {
public:
    int poorPigs(int buckets, int toDie, int toTest) {
        return ceil(log2(buckets)/log2((toTest/toDie)+1));
    }
};