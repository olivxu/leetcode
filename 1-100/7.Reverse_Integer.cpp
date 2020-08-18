class Solution {
public:
    int reverse(int x) {
        long result = 0;
        
        for(; x; result = result * 10 + x % 10, x/=10);
        return result > INT_MAX || result < INT_MIN ? 0: result; 
    }
};