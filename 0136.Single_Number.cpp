class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        int length = nums.size();
        
        // special case:
        if (length == 1)
            return nums[0];
        
        // normal case:
        for (int i = 0; i < length; i++) {
            result ^= nums[i];
        }
        return result;
    }
};