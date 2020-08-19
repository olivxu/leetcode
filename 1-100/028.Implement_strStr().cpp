class Solution {
public:
    int strStr(string haystack, string needle) {
        // special case 1: needle is empty string, return 0
        if (needle.size() == 0)
            return 0;
        
        // special case 2: needle is longer than haystack, return -1
        if (needle.size() > haystack.size())
            return -1;
        
        // normal case
        int i = 0, j = 0, k = i;
        
        while (haystack[i] && needle[j]) {
            if (haystack[i] == needle[j]) {
                i++;
                j++;
                continue;
            }
            else {
                k = k + 1;
                i = k;
                j = 0;
            }
        }
        
        if (needle[j] == '\0')
            return k;
        else
            return -1;
    }
};