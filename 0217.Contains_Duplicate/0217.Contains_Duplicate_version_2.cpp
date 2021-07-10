class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        map<int, int> appear;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            if (appear.count(nums[i]) != 0)
                return true;
            appear[nums[i]] = 1;
        }
        
        return false;
    }
};