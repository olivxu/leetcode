class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        stack<int> prev;
        int len = nums.size();
        vector<int> result(len, -1);
        
        for (int i = 0; i < len * 2; i++) {
            int num = nums[i % len];
            while (!prev.empty() && nums[prev.top()] < num) {
                result[prev.top()] = num;
                prev.pop();
            }
            if (i < len)
                prev.push(i);
        }
        return result;
    }
};