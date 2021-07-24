class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t result = 0;
        // 16 16换
        result = (n & 0xFFFF0000) >> 16 | (n & 0x0000FFFF) << 16;
        
        // 8 8 换
        result = (result & 0xFF00FF00) >> 8 | (result & 0x00FF00FF) << 8;
        
        // 4 4 换
        result = (result & 0xF0F0F0F0) >> 4 | (result & 0x0F0F0F0F) << 4;
        
        // 2 2 换
        result = (result & 0xCCCCCCCC) >> 2 | (result & 0x33333333) << 2;
        
        // 1 1 换
        result = (result & 0xAAAAAAAA) >> 1 | (result & 0x55555555) << 1;
        
        return result;
    }
};