/*
 * 卡过的bug：
 *     1.不论该字符是否出现在当前子串中 right都要加一
 *     2.test case: "     " 
 *       审题，是character不是letter, 不止26个英文字母
 *       所以不能单纯用一个长度为26的数组记录上一次出现的位置
 *      改用map
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // initialize
        int len = s.size();
        int left = 0;
        int right = 0;
        int maxLen = 0;
        map<char, int> appearRecord;
        
        // special case:
        if (len <= 1)
            return len;
        
        // normal case:
        for (int i = 0; i < len; i++) {
            // has appeared in current substring
            if (appearRecord.find(s[i]) != appearRecord.end() && appearRecord[s[i]] >= left)
                left = appearRecord[s[i]] + 1;  
            
            // update
            right++;
            maxLen = max(maxLen, right - left);
            appearRecord[s[i]] = i;
        }
        
        // return result
        return maxLen;      
    }
};