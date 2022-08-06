class Solution {
public:
    //int dp[][][];
    int poorPigs(int buckets, int toDie, int toTest) {
        return ceil(log(buckets)/log((toTest/toDie)+1));
    }
};