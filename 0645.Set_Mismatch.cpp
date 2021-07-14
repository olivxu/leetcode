class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int len = nums.size();
        vector<int> result(2);
        
        for (int i = 0; i < len; i++) {
            while (nums[i] != i + 1 && nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        }
        for (int i = 0; i < len; i++) {
            if (nums[i] != i + 1) {
                result[0] = nums[i];
                result[1] = i + 1;
            }
        }
        return result;
    }
};