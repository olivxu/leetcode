class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        int length = nums.size();
        
        // special case:
        if(length == 1)
            return nums[0];
        
        // normal case:
        for(int i = 0; i < length; i++) {
            if(!m.count(nums[i]))
                m[nums[i]] = 1;
            else
                m[nums[i]]++;
            if(m[nums[i]] > (length / 2))
                return nums[i];
        }
        return -1;
    }
};