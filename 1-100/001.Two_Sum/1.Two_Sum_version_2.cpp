class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result = {0, 0};
        
        for (int i = 0; i < nums.size(); i++) {
            m[target - nums[i]] = i;
        }
        
        for(int i = 0; i< nums.size(); i++) {
            if(m.find(nums[i]) != m.end() && i != m[nums[i]]) {
                result[0] = i;
                result[1] = m[nums[i]];
                return result;
            }
        }
        
        return result;
    }
};