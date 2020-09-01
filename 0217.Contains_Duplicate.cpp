class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> tmp;
        int length = nums.size();
        
        // special case:
        if (length <= 1)
            return false;
        
        // normal case:
        for (int i = 0; i < length; i++) {
            tmp.insert(nums[i]);
        }
        
        return (length != tmp.size());
    }
};