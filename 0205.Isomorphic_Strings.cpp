class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int> last_pos1;
        map<char, int> last_pos2;
        int len1 = s.size();
        int len2 = t.size();
        
        // special case:
        if (len1 != len2)
            return false;
        
        // normal case:
        //记录一个字符上次出现的位置，如果两个字符串中的字符上次出现的位置一样，那么就属于同构。
        for (int i = 0; i < len1; i++) {
            if (last_pos1.count(s[i]) == 0 && last_pos2.count(t[i]) == 0) {
                last_pos1[s[i]] = i;
                last_pos2[t[i]] = i;
            }
            else {
                if (last_pos1.count(s[i]) != 0 && last_pos2.count(t[i]) != 0) {
                    if (last_pos1[s[i]] != last_pos2[t[i]]) 
                        return false;
                    else {
                        last_pos1[s[i]] = i;
                        last_pos2[t[i]] = i;
                    }
                }
                else
                    return false;
            }
        }
        return true;
    }
};