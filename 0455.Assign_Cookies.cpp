class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        
        int sindex = 0;
        int gindex = 0;
        
        int slen = s.size();
        int glen = g.size();
            
        int cnt = 0;
        
        while (gindex < glen && sindex < slen) {
            while (sindex < slen && g[gindex] > s[sindex])
                sindex++;
            if (sindex < slen) {
                if (g[gindex] <= s[sindex]) {
                    gindex++;
                    sindex++;
                    cnt++;
                }
            }
            else
                break;
        }
        
        return cnt;
    }
};