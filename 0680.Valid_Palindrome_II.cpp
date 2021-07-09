class Solution {
public:
    bool validPalindrome(string s) {
        int len = s.size();
        int small = 0;
        int large = len - 1;
        
        while (small < large) {
            if (s[small] != s[large]) 
                return isPalindrome(s, small, large - 1) || isPalindrome(s, small + 1, large);
            else {
                small++;
                large--;
            }
        }
        
        return true;
    }
    
    bool isPalindrome(string s, int start, int end) {
        while (start < end) {
            if (s[start] != s[end])
                return false;
            else {
                start++;
                end--;
            }
        }
        return true;
    }
};