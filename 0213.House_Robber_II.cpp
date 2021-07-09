class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        vector<int> amount1(len - 1);
        vector<int> amount2(len);
        
        // special case:
        if (len == 1)
            return nums[0];
        if (len == 2)
            return max(nums[0], nums[1]);
        
        // normal case:
        // 1. 偷了第一家，不偷最后一家
        amount1[0] = nums[0];
        amount1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len - 1; i++) 
            amount1[i] = max(amount1[i - 2] + nums[i], amount1[i - 1]);
        
        // 2. 不偷第一家，偷最后一家
        amount2[0] = 0;
        amount2[1] = nums[1];
        amount2[2] = max(nums[1], nums[2]);
        for (int j = 3; j < len; j++) 
            amount2[j] = max(amount2[j - 2] + nums[j], amount2[j - 1]);
        
        return max(amount1[len - 2], amount2[len - 1]);   
    }
};