class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        // 先对所有数字进行一次异或，得到两个出现一次的数字的异或值。
        // 在异或结果中找到任意为 1 的位。
        // 根据这一位对所有的数字进行分组。
        // 在每个组内进行异或操作，得到两个数字。
        
        int num = 0;
        int len = nums.size();
        vector<int> result(2, 0);
        
        for (int i = 0; i < len; i++)
            num ^= nums[i];
        
        int classify = 1;
        while ((classify & num) == 0)
            classify = classify << 1;
        
        for (int i = 0; i < len; i++) {
            if ((nums[i] & classify) == 0) // 这里要注意 & 和 == 的优先级
                result[0] ^= nums[i];
            else
                result[1] ^= nums[i];
        }
        
        return result;
    }
};
