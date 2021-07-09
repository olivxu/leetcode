class Solution {
public:
    bool isAnagram(string s, string t) {
        int alphabet1[26] = {0};
        int alphabet2[26] = {0};
        int len1 = s.size();
        int len2 = t.size();
        
        // special case:
        if (len1 != len2) 
            return false;
        
        // normal case:
        for (int i = 0; i < len1; i++) 
            alphabet1[s[i] - 'a'] += 1;
        
        for (int j = 0; j < len2; j++)
            alphabet2[t[j] - 'a'] += 1;
        
        for (int k = 0; k < 26; k++) {
            if (alphabet1[k] != alphabet2[k])
                return false;
        }
        return true;
    }
};