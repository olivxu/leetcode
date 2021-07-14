/*
 * 位运算
 */
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int len = nums.size();
        int result = 0;
        int bit_max = get_bit_max(len); 
        
        for (int bit = 0; bit <= bit_max; bit++) {
            int x = 0;
            int y = 0;
            for (int i = 0; i < len; i++) {
                if (nums[i] & (1 << bit))
                    x++;
                if (i > 0 && (i & (1 << bit)))
                    y++;
            }
            if (x > y) 
                result |= (1 << bit);
        }
        return result;
    }
    
    int get_bit_max(int n) {
        int bit_max = 31;
        
        while ((n - 1) >> bit_max != 1)
            bit_max--;
        
        return bit_max;
    }
};
