class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int> > m; // 0: 个数 1: left 2: right
        int len = nums.size();
        
        for (int i = 0; i < len; i++) {
            if (m.count(nums[i]) == 0) {
                m[nums[i]] = {1, i, i};
            }
            else {
                m[nums[i]][0]++;
                m[nums[i]][2] = i;
            }
        }
        
        int max_count = 0;
        int min_len = len + 1;
        
        for (auto &[_, vec]: m) {
            if (max_count < vec[0]) {
                max_count = vec[0];
                min_len = vec[2] - vec[1] + 1;
            }
            else if (max_count == vec[0]) {
                if (vec[2] - vec[1] + 1 < min_len)
                    min_len = vec[2] - vec[1] + 1;
            }
        }
        
        return min_len;
    }
};