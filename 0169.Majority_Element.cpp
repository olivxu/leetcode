class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int majorElement;
        int times;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            // 第一个数
            if (i == 0) {
                majorElement = nums[0];
                times = 1;
            }
            // 其余的数
            else {
                // 和当前出现最多的数相同
                if (nums[i] == majorElement) 
                    times += 1;
                else {
                    if (times > 0)
                        times -= 1;
                    else {
                        majorElement = nums[i];
                        times = 1;
                    }
                }
            }
        }
    return majorElement;
    }
};