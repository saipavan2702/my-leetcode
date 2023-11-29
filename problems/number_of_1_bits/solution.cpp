class Solution {
public:
    int hammingWeight(uint32_t n) {
        bitset<32>bit(n);
        return bit.count();
    }
};