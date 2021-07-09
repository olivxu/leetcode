class Solution {
public:
    int count = 0;
    
    int countSubstrings(string s) {
        for (int i = 0; i < s.size(); i++) {
            countPalindromic(s, i, i); // 奇数长度
            countPalindromic(s, i, i + 1); // 偶数长度
        }
        return count;
    }
    
    void countPalindromic(string s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            left--;
            right++;
            count++;
        }
    }
};