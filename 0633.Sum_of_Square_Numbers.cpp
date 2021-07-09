/*
 * 踩坑记录：需要处理溢出 e.g. 829921 + 2146654224
 */

class Solution {
public:
    bool judgeSquareSum(int c) {
        int small = 0;
        int large = int(sqrt(c));
        
        while (small <= large) {
            // special case: 处理溢出
            if (large * large > INT_MAX - small * small)
                large --;
            
            // normal case:
            int square_sum = small * small + large * large;
            if (square_sum == c)
                return true;
            if (square_sum > c)
                large--;
            if (square_sum < c)
                small++;
        }
        
        return false;
    }
};