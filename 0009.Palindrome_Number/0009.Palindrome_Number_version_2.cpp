/*
 * 踩坑记录: 10
 */
class Solution {
public:
    bool isPalindrome(int x) {
        // special case:
        if (x == 0)
            return true;
        
        else if (x < 0 || x % 10 == 0)
            return false;
        
        // normal case:
        int right = 0;
        int tmp = x;
        while (tmp > 0) {
            // overflow
            if (right > (INT_MAX - tmp % 10) / 10)
                return false;
            right = right * 10 + tmp % 10;
            tmp /= 10;
        }
        return x == right;
    }
};