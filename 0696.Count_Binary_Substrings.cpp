class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0;
        int curr = 1;
        int count = 0;
        int len = s.size();
        
        // special case:
        if (len == 1)
            return 0;
        
        for (int i = 1; i < len; i++) {
            if (s[i] == s[i - 1]) {
                curr++;
            }
            else {
                prev = curr;
                curr = 1;
            }
            if (prev >= curr)
                count++;
        }
        return count;
    }
};