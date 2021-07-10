class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;
        int len = nums.size();
        
        for (int i = 0; i < len; i++) 
            num_set.insert(nums[i]);
        
        int longest = 0;
        
        for (int num: num_set) {
            if (num_set.count(num - 1) == 0) {
                int target = num + 1;
                int count = 1;
                while (num_set.count(target) != 0) {
                    count += 1;
                    target++;
                }
                longest = max(longest, count);
            }
        }
        return longest;
    }
};