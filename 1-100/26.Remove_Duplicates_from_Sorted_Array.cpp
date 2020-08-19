class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        // special case: there is no element in the vector, or there is only one element in the vector
        if (nums.size() < 2)
            return nums.size();

        // normal case
        int j = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            if (nums[j] != nums[i])
                j++;
            nums[j] = nums[i];
        }
        return ++j;
            
    }
};