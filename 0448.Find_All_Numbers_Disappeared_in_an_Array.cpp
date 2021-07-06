class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        // 将所有正数作为数组下标，置对应数组值为负值。那么，仍为正数的位置即为（未出现过）消失的数字。
        int len = nums.size();
        vector<int> result;
        for (int i = 0; i < len; i++) 
            nums[abs(nums[i]) - 1] = -1 * abs(nums[abs(nums[i]) - 1]);
        for(int i = 0; i < len; i++) {
            if (nums[i] > 0) {
                result.push_back(i + 1);
            }
        }
        return result;
    }
};