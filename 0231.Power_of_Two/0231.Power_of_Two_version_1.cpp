class Solution {
public:
    bool isPowerOfTwo(int n) {
        // special case:
        if (n <= 0)
            return false;
        
        // normal case:
        return (((1 << 30) % n) == 0);
    }
};