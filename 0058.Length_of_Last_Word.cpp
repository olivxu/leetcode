class Solution {
public:
    int lengthOfLastWord(string s) {
        int len = 0;
        int i = s.size() - 1;
        
        // ignore all the blanks at the end of the string
        while(i > 0 && s[i] == ' ')
            i--;
        
        while(i >= 0 && s[i] != ' ') {
            len++;
            i--;
        }
        
        return len;
    }
};