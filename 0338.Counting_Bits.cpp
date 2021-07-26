class Solution {
public:
    vector<int> countBits(int n) {
        // 动态规划
        vector<int> result(n+1);
        result[0] =0;

        // i & (i - 1) 能去掉最右侧的1
        for (int i = 1; i < n + 1; i++) 
            result[i] = result[i & (i - 1)] + 1;

        return result;
    }
};