// 方法二：单指针法，遍历两遍，不借助其他数据结构
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int flag = 0;
        int len = nums.size();
        
        // 遍历第一遍，把0放到最前面
        for (int i = 0; i < len; i++) {
            if (nums[i] == 0) {
                swap(nums[flag], nums[i]);
                flag++;
            }
        }
        // 遍历第二遍，把1放到合适的位置
        for (int i = flag; i < len; i++) {
            if (nums[i] == 1) {
                swap(nums[flag], nums[i]);
                flag++;
            }
        }
    }
};