class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> m;
        vector<int> result = {0, 0};
        
        for(int i = 0; i< nums.size(); i++) {
            int complement = target - nums[i];
            map<int, int>::iterator iter;
            iter = m.find(complement);
            if(iter != m.end()) {
                result[0] = iter->second;
                result[1] = i;
                return result;
            }
            else 
                m[nums[i]]= i;
        }
        return result;
    }
};