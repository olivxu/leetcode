// 方法一：遍历两遍
class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int len = nums.size();
        
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1]) {
                if (i == len - 2) 
                    return true;
                if (i < len - 2 && nums[i] < nums[i + 2])
                    nums[i + 1] = nums[i];
                else 
                    nums[i] = nums[i + 1];
                break;
            }
        }
        
        for (int i = 0; i < len - 1; i++) {
            if (nums[i] > nums[i + 1])
                return false;
        }
        
        
        return true;
    }
};