class Solution {
public:
    bool isPalindrome(int x) {
        // special case 1: negative number, false
        if (x < 0)
            return false;
        
        // special case 2: 0 1 2 3 4 5 6 7 8 9, true
        else if (x < 10)
            return true;
        
        // normal case
        else
        {
            stack<int> stack0;
            int rest = x;
            
            while(rest > 0)
            {
                int last_digit = rest % 10;
                stack0.push(last_digit);
                rest = rest / 10;
            }
            
            while(!stack0.empty())
            {
                int original = x % 10;
                int stacked = stack0.top();
                if (stacked != original)
                    return false;
                else
                {
                    x /= 10;
                    stack0.pop();
                }
            }
            return true;
        }
    }
};