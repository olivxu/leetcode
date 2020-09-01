class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int result = 0;
        int count = 0;
        int length = nums.size();
        
        // special case 1: assume all the number in nums are not negative
        if (length == 0)
            return -1;
        
        // special case 2: 
        if (length == 1)
            return nums[0];
        
        // normal case:
        for(int i = 0; i < length; i++) {
            if (count == 0) {
                result = nums[i];
                count++;
            }
            else if (result == nums[i])
                count++;
            else
                count--;
        }
        return result;
    }
};