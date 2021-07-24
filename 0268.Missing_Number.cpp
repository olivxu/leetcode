class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // 三种方法
        // 1. 排序
        // 2. 哈希表
        // 3. 位运算
        int len = nums.size();
        int num = 0;
        
        for (int i = 0; i < len; i++)
            num = num ^ nums[i] ^ (i + 1);
        
        return num;
    }
};