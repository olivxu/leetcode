/*
 * 踩坑记录：需要考虑大写
 */

class Solution {
public:
    char vowels[10] = {'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'};
    
    string reverseVowels(string s) {
        int len = s.size();
        int small = 0;
        int large = len - 1;
        
        while (small < large) {
            bool is_small_vowel = isVowel(s[small]);
            bool is_large_vowel = isVowel(s[large]);
            // 都是元音
            if (is_small_vowel && is_large_vowel) {
                swap(s[small], s[large]);
                small++;
                large--;
                continue;
            }
            // small不是元音，large是元音
            if (is_large_vowel) {
                small++;
                continue;
            }
            // large不是元音，small是元音
            if (is_small_vowel) {
                large--;
                continue;
            }
            // 都不是元音
            small++;
            large--;
        }
        return s;
    }
    
    bool isVowel(char c) {
        for (int i = 0; i < 10; i++) {
            if (c == vowels[i])
                return true;
        }
        return false;
    }
};