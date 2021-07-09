class Solution {
public:
    int rob(vector<int>& nums) {
        int len = nums.size();
        
        // special case:
        if (len == 1)
            return nums[0];
        
        if (len == 2)
            return max(nums[0], nums[1]);
        
        // normal case:
        vector<int> amount(len);
        amount[0] = nums[0];
        amount[1] = max(nums[0], nums[1]);
        for (int i = 2; i < len; i++) 
            amount[i] = max(nums[i] + amount[i - 2], amount[i - 1]);
        
        return amount[len - 1];
    }
};