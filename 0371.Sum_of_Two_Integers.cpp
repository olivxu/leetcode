class Solution {
public:
    int getSum(int a, int b) {
        return b == 0 ? a : getSum(a ^ b, uint32_t(a & b) << 1);   
    }
};