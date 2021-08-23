// 方法三：双指针法，遍历一遍，不借助其他数据结构
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int len = nums.size();
        int zero = 0;
        int two = len - 1;
        
        for (int i = 0; i < len; i++) {
            while (i <= two && nums[i] == 2) {
                swap(nums[two], nums[i]);
                two--;
            }
            
            if (nums[i] == 0) {
            swap(nums[zero], nums[i]);
            zero++;
            }
        }
        
    }
};