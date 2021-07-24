/*
 * 索引 i 和 j 中的两个元素都不会导致跳转到相同的索引 k，
 * 因为它需要 nums[i] = nums[j] = k，这是不可能的，因为所有元素都是不同的。
 * 此外，由于相同的推理，任何循环外的元素都不会导致循环内的元素。
 * 因此，record 集合的使用正确。
 * 放进循环里反而会超过时间限制。
 */
class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        unordered_set<int> record;
        int len = nums.size();
        int max_cnt = 0;
        
        for (int i = 0; i < len; i++) {
            int j = i;
            int cnt = 0;
            while (true) {
                if (record.count(nums[j]) == 0) {
                    cnt++;
                }
                else
                    break;
                record.insert(nums[j]);
                j = nums[j];
            }
            max_cnt = max(max_cnt, cnt);
        }
        return max_cnt;
    }
};