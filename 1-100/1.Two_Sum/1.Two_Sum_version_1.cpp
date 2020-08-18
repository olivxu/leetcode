class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> result = {0, 0};
        int length = nums.size();
        for (int i = 0; i < length; i++) {
            for (int j = i + 1; j < length; j++) {
                if (nums[i] + nums[j] == target) {
                    result[0] = i;
                    result[1] = j;    
                }
            }
        }
        return result;
    }
};