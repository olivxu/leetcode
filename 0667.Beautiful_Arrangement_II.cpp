class Solution {
public:
    vector<int> constructArray(int n, int k) {
        // 使用两种特殊数组来构造
        // k最小：差值为1的等差数列
        // k最大：最小值与最大值交替出现 e.g. 162534, 差值为1-n-1
        // 只需要将这两种情况结合起来
        // 后半部分用k最大来构造
        // 前半部分用k最小来构造
        // 前半部分和后半部分衔接的地方差值为1，不影响结果，不用特殊考虑
        
        vector<int> result(n);
        for (int i = 0; i < n - k - 1; i++) {
            result[i] = i + 1;
        }
        
        int j = 0;
        int left = n  - k;
        int right = n;
        for (int i = n - k - 1; i < n; i++) {
            if (j % 2 == 0)
                result[i] = left++;
            else
                result[i] = right--;
            j++;
        }
        
        return result;
    }
};