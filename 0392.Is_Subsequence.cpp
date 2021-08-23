class Solution {
public:
    bool isSubsequence(string s, string t) {
        int slen = s.size();
        int tlen = t.size();
        
        if (slen == 0)
            return true;
        
        int sindex = 0;
        int tindex = 0;
        
        while (sindex < slen && tindex < tlen) {
            if (s[sindex] == t[tindex]) {
                sindex++;
                tindex++;
            }
            else
                tindex++;
        }
        
        return sindex == slen;
    }
};