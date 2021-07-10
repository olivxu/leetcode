class Solution {
public:
    int findLHS(vector<int>& nums) {
        map<int, int> m;
        int MAX;
        int len = nums.size();
        
        // 让map[i]存放i和i+1的个数
        for (int i = 0; i < len; i++) {
            if (m.count(nums[i]) == 0) 
                m[nums[i]] = 1;
            else
                m[nums[i]] += 1;
            if (m.count(nums[i] - 1) != 0)
                MAX = max(MAX, m[nums[i]] + m[nums[i] - 1]);
            if (m.count(nums[i] + 1) != 0)
                MAX = max(MAX, m[nums[i]] + m[nums[i] + 1]);
        }
        return MAX;
    }
};