class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int currIndex = 0;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            if (nums[i] != 0) {
                nums[currIndex] = nums[i];
                currIndex++;
            }
        }
        for (int i = currIndex; i < len; i++) {
            nums[i] = 0;
        }
    }
};