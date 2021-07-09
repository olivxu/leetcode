class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int len = nums.size();
        int result = 0;
        
        // special case:
        if (len == 1){
            if (k != nums[0])
                return 0;
            else 
                return 1;
        }
            
        // normal case:
        vector<int> cumulative(len + 1, 0);
        for (int i = 1; i <= len; i++) 
            cumulative[i] = cumulative[i - 1] + nums[i - 1];
        
        map<int, int> count_map;
        for (int i = 0; i <= len; i++) {
            int target = cumulative[i] - k;
            if (count_map.count(target) != 0) 
                result += count_map[target];
            if (count_map.count(cumulative[i]) != 0)
                count_map[cumulative[i]]++;
            else
                count_map[cumulative[i]] = 1;
        }
        
        return result;
    }
};