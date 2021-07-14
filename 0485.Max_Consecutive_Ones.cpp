class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int len = nums.size();
        int start = 0;
        int MAX = 0;
        
        for (int i = 0; i < len; i++) {
            if (nums[i] == 1) {
                if (start != -1)
                    MAX = max(MAX, i - start + 1);
                else {
                    start = i;
                    MAX = max(MAX, 1);
                }
            }
            else
                start = -1;
        }
        return MAX;    
    }
};