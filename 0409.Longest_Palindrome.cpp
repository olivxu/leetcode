class Solution {
public:
    int longestPalindrome(string s) {
        int letter[52] = {0};
        int len = s.size();
        
        for (int i = 0; i < len; i++) 
            if (s[i] <= 'z' && s[i] >= 'a')
                letter[s[i] - 'a'] += 1;
            else
                letter[s[i] - 'A' + 26] += 1;
        
        int odd_flag = 0;
        int result = 0;
        
        for (int j = 0; j < 52; j++) {
            if (letter[j] % 2 == 0)
                result += letter[j];
            else {
                odd_flag = 1;
                result += letter[j] - 1;
            }
        }
        
        return result + odd_flag;
    }
};