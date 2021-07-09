class Solution {
public:
    bool isPalindrome(string s) {
        int len = s.size();
        int small = 0;
        int large = len - 1;
                        
        while (small < large) {
            // small不是数字或字符
            if (!isAlphanumeric(s[small])) {
                small++;
                continue;
            }
            // large不是数字或字符
            if (!isAlphanumeric(s[large])) {
                large--;
                continue;
            }
            if (toLowerCase(s[small]) != toLowerCase(s[large]))
                return false;
            else {
                large--;
                small++;
            }
            
        }
        return true;
    }
    
    bool isAlphanumeric(char c) {
        if ((c >= '0' && c <= '9') || (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
            return true;
        return false;
    }
    
    char toLowerCase(char c) {
        if (c >= 'A' and c <= 'Z')
            return c - 'A' + 'a';
        else return c;
    }
};