/*
 * 位运算
 */

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> result(n+1);
        result[0] = 0;
        
        for (int i = 1 ; i < n + 1; i++) {
            if (i % 2 == 1)
                result[i] = result[i >> 1] + 1;
            else
                result[i] = result[i >> 1];
        }
        return result;
    }
};