/*
 * 踩坑记录：直接访问dictionary[i]在leetcode会heap buffer overflow
 */
class Solution {
public:
    string findLongestWord(string s, vector<string>& dictionary) {
        int max_len = 0;
        string longest_word = "";
        int len = s.size();
        
        for (string target: dictionary) {
            if (target.size() < max_len) 
                continue;
            if (isSubStr(s, target)) {
                if (target.size() == max_len) {
                    if (target < longest_word)
                        longest_word = target;
                }
                else if (target.size() > max_len) {
                    max_len = target.size();
                    longest_word = target;
                }
            }
        }
        return longest_word;
    }
    
    bool isSubStr(string s, string target) {
        int i = 0;
        int j = 0;
        int len1 = s.size();
        int len2 = target.size();
        
        while (i < len1 && j < len2) {
            if (s[i] == target[j]) {
                i++;
                j++;
            }
            else
                i++;
        }
        
        return (j == len2);
    }
};