class Solution {
public:
    int mySqrt(int x) {
        // special case:
        if(x <= 1)
            return x;
        
        // normal case:
        long result = x;
        
        while(result > x / result)
        {
            result = (result + x / result) / 2;
        }
            
        return result;
        
    }
};