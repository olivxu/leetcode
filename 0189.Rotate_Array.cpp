class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int len = nums.size();
        k = k % len;
        // 1. 翻转整个数组
        reverse_array(nums, 0, len - 1);
        // 2. 翻转左半边数组
        reverse_array(nums, 0, k - 1);
        // 3. 翻转右半边数组
        reverse_array(nums, k, len - 1);
    }
    void reverse_array(vector<int>& nums, int start, int end) {
        for (int i = 0; i < (end -  start + 1) / 2; i++)
            swap(nums[start + i], nums[end - i]);
    }
};