class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int low, mid, high;
        int length = nums.size();
        
        low = 0;
        high = length - 1;
        
        // special case: target is larger then all the elements in vector
        if(target > nums[high])
            return length;
        
        // normal case: search for place to insert into
        while(low < high) {
            mid = (low + high) / 2;
            
            // situation 1: find
            if(target == nums[mid]) 
                return mid;
                    
            // situation 2: target is larger than mid
            if(target > nums[mid])
                low = mid + 1;
            
            // situation 3: taregt is smaller than mid
            if(target < nums[mid])
                high = mid;
        }
        
        return low;
        
        
    }
};