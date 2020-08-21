class Solution {
public:
    int climbStairs(int n) {
        // special case: 
        if(n <= 3)
            return n;
        
        // normal case:
        int first = 2;
        int second = 3;
        
        for(int i = 4; i <= n; i++) {
            int tmp = first + second;
            first = second;
            second = tmp;
        }
        
        return second;
        
    }
};