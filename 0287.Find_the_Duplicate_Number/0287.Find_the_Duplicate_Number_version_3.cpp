/*
 * 二分查找
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 1;
        int right = len - 1;
        int result = 0;
        
        while (left <= right) {
            int middle = (left + right) / 2;
            int count = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] <= middle)
                    count++;
            }
            if (count <= middle)
                left = middle + 1;
            else {
                right = middle - 1;
                result = middle;
            }
        }
        return result;
    }
};
