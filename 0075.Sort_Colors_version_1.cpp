// 方法一：遍历两遍，使用map
class Solution {
public:
    void sortColors(vector<int>& nums) {
        map<int, int> m;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            if (m.count(nums[i]) != 0)
                m[nums[i]]++;
            else
                m[nums[i]] = 1;
        }
        
        int curr = 0;
        for (int i = 0; i < 3; i++) {
            if (m.count(i) != 0) {
                for (int j = 0; j < m[i]; j++) {
                    nums[curr] = i;
                    curr++;
                }
            }
        }
    }
};