// 二分法
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int len = nums.size();
        int left = 0;
        int right = len - 1;
        int mid = (left + right) / 2;

        // special case:
        if (len == 1)
            return nums[0];

        // normal case:
        // right - left 一定为 0 2 4 ...
        while (left <= right) {
            mid = (left + right) / 2;

            // right - left == 0
            if (left == right)
                return nums[mid];
            
            if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
                return nums[mid];

            // right - left == 2
            if (right - left == 2 && nums[mid] != nums[mid - 1])
                return nums[mid - 1];

            if (right - left == 2 && nums[mid] != nums[mid + 1])
                return nums[mid + 1];

            // searching left
            if (nums[mid] == nums[mid - 1]) {
                if  ((mid - left) % 2 == 0)
                    right = mid - 2;
                else
                    left = mid + 1;
            }
            // searching right
            else
                if ((mid - right) % 2 == 0)
                    left = mid + 2;
                else
                    right = mid - 1;
        }
        return nums[mid];
    }
};